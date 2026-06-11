#include<iostream>
using namespace std;

int main()
{
    int s,n,x1=3,x2,r[4]={0},i=3;
    cin>>s;
    n=4;
    for(i=0;i<n;i++)
    {
        r[x1]=s%10;
        s=s/10;
        x1--;
    }
    x2=r[2]*10+r[3];
    x1=r[0]*10+r[1];
    if(x1==0 && x2==0)
    {
        cout<<"NA";
    }
    else if(x1>0 && x1<=12 && x2>0 && x2 <=12)
    {
        cout<<"AMBIGUOUS";
    }
    else if(x2>0 && x2<=12 && x1>12)
    {
        cout<<"YYMM";
    }
    else if(x1>0 && x1<=12 && x2>12)
    {
        cout<<"MMYY";
    }
    else if(x1==0 && x2<=12)
    {
        cout<<"YYMM";
    }
    else if(x2==0 && x1<=12)
    {
        cout<<"MMYY";
    }
    else
        cout<<"NA";
    return 0;

}
