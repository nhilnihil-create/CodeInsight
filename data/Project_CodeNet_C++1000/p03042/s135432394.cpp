#include<iostream>
using namespace std;
int main()
{
    int t,n,s,s1,s2;
    cin >> s;
    s2=s%100;
    s1=s/100;
    if((s1!=0 && s2!=0) && (s1<=12) && (s2<=12))
    {
        cout<<"AMBIGUOUS";
    }

    else  if((s1!=0) &&(s1<=12))
    {
        cout<<"MMYY";
    }
    else if((s2!=0)&&(s2<=12))
    {
        cout<<"YYMM";
    }

    else
    {
        cout<<"NA";
    }

}