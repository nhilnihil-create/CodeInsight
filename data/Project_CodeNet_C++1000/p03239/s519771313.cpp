#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,id,v,m=1005;
    cin>>n>>t;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>id>>v;
        mp[id]=v;
    }
    id=1005;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second <= t)
        {
            id=min(id,it->first);
        }
    }

    if(id!=1005)cout<<id<<endl;
    else cout<<"TLE\n";


    return 0;
}
