#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,i;
    cin>>n;
    long long v[n],c[n],x=0,y=0;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>c[i];
        if(v[i]>c[i])
        {
            x=x+v[i];
            y=y+c[i];
        }
    }
    cout<<x-y;
    return 0;
}