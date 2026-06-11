#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,a;
    cin>>n>>a;
    if(n<500)
    {
        if(a>=n)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
            
        }
    }
    else
    {
        n=n%500;
        if(n<=a)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
}