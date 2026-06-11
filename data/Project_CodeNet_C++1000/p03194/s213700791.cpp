#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,p,i;
    cin>>n>>p;
    set<ll> s;
    for(i=1;i*i<=p;i++)
        if(p%i==0)
            s.insert(i),s.insert(p/i);
    vector<ll> div;
    for(auto in:s)
        if(in!=1)
            div.push_back(in);
    vector<ll> v;
    ll tmp=p;
    for(auto in:div)
        while(tmp%in==0)
            v.push_back(in),tmp/=in;
    map<ll,ll> m;
    for(auto in:v)
        m[in]++;
    ll ans=1;
    for(auto in:m)
    {
        ll x=in.second/n;
        ll y=1;
        for(i=0;i<x;i++)
            y*=in.first;
        ans*=y;
    }
    cout<<ans<<endl;
}

