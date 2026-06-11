#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long r,d,x;
    cin>>r>>d>>x;
    for(int i=1;i<=10;i++)
    {
        x=x*r-d;
        cout<<x<<"\n";
    }
}