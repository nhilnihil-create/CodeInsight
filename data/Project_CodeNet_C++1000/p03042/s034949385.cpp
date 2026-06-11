#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s;
    cin>>s;
    int d=s/100;
    int m=s%100;
    if((d<=12 && m>12 && d!=0) || (d<=12 && d!=0 && m==0))
        cout<<"MMYY\n";
    else if((d>12 && m<=12 && m!=0) || (m<=12 && m!=0 && d==0))
        cout<<"YYMM\n";
    else if(d<=12 && m<=12 && d!=0 && m!=0)
        cout<<"AMBIGUOUS\n";
    else if(d>12 && m>12 || d==0 && m==0 || d>12 && m==0||d==0 && m>12)
        cout<<"NA\n";
}

