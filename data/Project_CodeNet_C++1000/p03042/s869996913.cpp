#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    int s,a,b;
    cin>>s;
    a=s/100;
    b=s%100;

    if(a>12)
    {
        if(b>0&&b<=12)
            cout<<"YYMM"<<endl;
        else
            cout<<"NA"<<endl;
    }
    else if(a==0)
    {
        if(b==0||b>12)
            cout<<"NA"<<endl;
        else
            cout<<"YYMM"<<endl;
    }
    else
    {
        if(b==0||b>12)
            cout<<"MMYY"<<endl;
        else
            cout<<"AMBIGUOUS"<<endl;
    }

    return 0;
}



