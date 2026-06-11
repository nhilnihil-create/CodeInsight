#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,ct=0;
    cin>>n;

    int v[n];
    int c[n];
    for(int i=0;i<n;i++){cin>>v[i];}
    for(int i=0;i<n;i++){cin>>c[i];}

    for(int i=0;i<n;i++)
    {ct+=max(0,v[i]-c[i]);}
    cout<<ct<<endl;
}
