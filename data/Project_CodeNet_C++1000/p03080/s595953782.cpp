#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    int n,c=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
         c++;
    }
    if(c>n-c)
     cout<<"Yes";
    else
    cout<<"No";}