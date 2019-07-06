//
//  main.cpp
//  文件传输14
//
//  Created by s20181106119 on 2019/7/6.
//  Copyright © 2019 s20181106119. All rights reserved.
//
//
//  main.cpp
//  文件传输12
//
//  Created by s20181106119 on 2019/7/3.
//  Copyright © 2019 s20181106119. All rights reserved.
//
#define TOTAL 20
#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct student{
    char name1[TOTAL];
    char number[50];
    char  colleage[50];
    char  speciality[50];
    double average;
    double score[TOTAL];
};
struct referee{
    char name2[7];
    double score[TOTAL];
};
int compare(student  &p1,student &p2)
{
    if(p1.average>p2.average)
    {
        return true;
    }
    else if(p1.average==p2.average)
    {
        if(p1.name1-p2.name1>0)
        {
            return true ;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int main()
{
    struct student student[TOTAL];
    struct  referee referee[7];
    ifstream in("/Users/s20181106119/Desktop/学生信息.txt");
    int i;
    for(i=0;i<TOTAL;i++)
    {
        in>>student[i].name1>>student[i].number>>student[i].colleage>>student[i].speciality;
    }
    ifstream inf ("/Users/s20181106119/Desktop/裁判信息及分数.txt");
    int l,j,sum=0;
    for(l=0;l<7;l++)
    {
        inf>>referee[l].name2;
        for(j=0;j<TOTAL;j++)
        {
            inf>>referee[l].score[j];
        }
    }
    for(i=0;i<TOTAL;i++)
    {
        for(j=0;j<7;j++)
        {
            student[i].score[j]= referee[j].score[i];
        }
    }
    for(i=0;i<TOTAL;i++)
    {
        sort(student[i].score,student[i].score+7);
    }
    for(j=0;j<TOTAL;j++)
    {
        for(l=1;l<6;l++)
        {
            sum=sum+student[j].score[l];
        }
        student[j].average=1.0*sum/5;
        sum=0;
    }
    sort(student,student+TOTAL,compare);
    ofstream output("/Users/s20181106119/Desktop/最终排名.txt");
    if(output.is_open())
    {
        int i;
        output<<left<<setw(21)<<"学生姓名"
        <<left<<setw(18)<<"学院"
        <<left<<setw(13)<<"学号"
        <<left<<setw(15)<<"专业"
        <<left<<setw(10)<<"最终成绩"
        <<"      名次"<<endl;
        for(i=0;i<TOTAL;i++)
        {
            output<<left<<setw(15)<<student[i].name1
            <<left<<setw(15)<<student[i].colleage
            <<left<<setw(10)<<student[i].number
            <<left<<setw(15)<<student[i].speciality
            <<left<<setw(10)<<fixed<<setprecision(2)<<student[i].average
            <<" "<<i+1<<endl;
        }
        output.close();
    }
}

