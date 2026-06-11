#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    string s;
    cin>>s;
    int a = s[0] -'0';
    int b = s[1] -'0';
    int c = s[2] -'0';
    int d = s[3] -'0';

    if( a+b+c+d == 7)
    {
        cout<<a<<"+"<<b<<"+"<<c<<"+"<<d<<"="<<7;
    }
    else if( a+b+c-d == 7)
    {
        cout<<a<<"+"<<b<<"+"<<c<<"-"<<d<<"="<<7;
    }
    else if( a+b-c+d == 7)
    {
        cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"="<<7;
    }
    else if( a-b+c+d == 7)
    {
        cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"="<<7;
    }
    else if( a+b-c-d == 7)
    {
        cout<<a<<"+"<<b<<"-"<<c<<"-"<<d<<"="<<7;
    }
    else if( a-b+c-d == 7)
    {
        cout<<a<<"-"<<b<<"+"<<c<<"-"<<d<<"="<<7;
    }
    else if( a-b-c+d == 7)
    {
        cout<<a<<"-"<<b<<"-"<<c<<"+"<<d<<"="<<7;
    }
    else if( a-b-c-d == 7)
    {
        cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"="<<7;
    }
}