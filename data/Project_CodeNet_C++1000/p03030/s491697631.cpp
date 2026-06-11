#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,t;
    string s;
    cin>>n;
    pair<pair<string,int>,int> p[101];
    for(int j=0;j<n;j++)
    {
        cin>>s>>t;
        p[j]=make_pair(make_pair(s,-t),j);
    }
    sort(p,p+n);
    for(int j=0;j<n;j++)
    {
        cout<<p[j].second+1<<"\n";
    }
}