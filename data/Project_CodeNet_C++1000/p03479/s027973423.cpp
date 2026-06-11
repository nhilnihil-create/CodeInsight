#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y,ct=0;
    cin>>x>>y;
    if(x==y){cout<<"1"<<endl; return 0;}
    while(x<=y){x*=2;ct++;}
    cout<<ct<<endl;
}

