#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i;
    cin>>n>>t;
    map<int,int>mp;
    for(i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[x]=y;
    }
    for(auto x:mp)
    {
        if(x.second<=t)
        {
            cout<<x.first;
            return 0;
        }
    }
    cout<<"TLE";

}
