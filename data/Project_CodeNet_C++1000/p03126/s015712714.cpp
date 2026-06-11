#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{

    ll n,m;
    cin>>n>>m;
    ll d=n;
    map<ll,ll>mp;
    ll cnt=0;
    while(d--)
    {
        ll x;
        cin>>x;
        for(int i=0;i<x;i++)
        {
            ll k;
            cin>>k;
            mp[k]++;
        }

    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        ll x=it->second;
        if(x==n)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;


}
