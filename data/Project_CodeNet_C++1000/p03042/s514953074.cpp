#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    bool temp=false;
    bool temp2=false;
    if(str[2]=='0')
    {
        if(str[3]>='1'&&str[3]<='9')
        {
            temp=true;
        }
    }
    else if(str[2]=='1')
    {
        if(str[3]>='0'&&str[3]<='2')
        {
            temp=true;
        }
    }
    if(str[0]=='0')
    {
        if(str[1]>='1'&&str[1]<='9')
        {
            temp2=true;
        }
    }
    else if(str[0]=='1')
    {
        if(str[1]>='0'&&str[1]<='2')
        {
            temp2=true;
        }
    }
    if(temp&&temp2)
    {
        cout<<"AMBIGUOUS\n";
    }
    else if(temp)
    {
        cout<<"YYMM\n";
    }
    else if(temp2)
    {
        cout<<"MMYY\n";
    }
    else
    {
        cout<<"NA\n";
    }
    return 0;
}