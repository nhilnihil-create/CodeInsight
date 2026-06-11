#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;

bool cmp(pair<pair<string,ll>,ll> a,pair<pair<string,ll>,ll> b)
{
    if(a.ff.ff<b.ff.ff) return true;
    else if(a.ff.ff==b.ff.ff)
    {
        if(a.ff.ss>b.ff.ss) return true;
        else return false;
    }
    return false;
}

int main()
{
    ll a,b,i,j,n,t;
    cin>>n;
    vl<pair<pair<string,ll>,ll>> p;
    for(i=0;i<n;i++)
    {
        string s;
        cin>>s>>a;
        p.pb({{s,a},i+1});
    }
    sort(p.begin(),p.end(),cmp);
    for(i=0;i<n;i++) cout<<p[i].ss<<endl;
}