/*
    Author: aksayushx
*/
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
 
ll n;
vector<ll> h,a,dp;
vector<ll> segtree;
ll siz=1;
void init(ll x)
{
    while(siz<x)
    siz*=2;
    segtree.assign(2*siz,0);
}
void sets(ll i,ll v,ll x,ll lx,ll rx)
{
    if(rx-lx==1)
    {
        segtree[x]=v;
        return;
    }
    ll m=(lx+rx)/2;
    if(i<m)
        sets(i,v,2*x+1,lx,m);
    else
        sets(i,v,2*x+2,m,rx);
    segtree[x]=max(segtree[2*x+1],segtree[2*x+2]);
}
void setNum(ll i,ll v)
{
    sets(i,v,0,0,siz);
}
ll getSu(ll l,ll r,ll x,ll lx,ll rx)
{
    if(l>=rx || lx>=r)
    return 0;
    if(lx>=l && rx<=r)
    return segtree[x];
    ll m=(lx+rx)/2;
    ll s1=getSu(l,r,2*x+1,lx,m);
    ll s2=getSu(l,r,2*x+2,m,rx);
    return max(s1,s2);
    
}
ll getMax(ll l, ll r)
{
    return getSu(l,r,0,0,siz);
}

void aksayushx()
{
    cin>>n;
    h.resize(n);
    a.resize(n);
    init(n);
    for(ll i=0;i<n;i++) cin>>h[i];
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> dp(n+1,0);
    //dp[i] is the max beauty including flower i
    dp[0]=0;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll height=h[i];
        ll add=getMax(0,height);
        //get max beauty for heights 1...h[i]
        dp[height]=a[i];
        //for(ll j=1;j<h[i];j++)
        dp[h[i]]=max(dp[h[i]],a[i]+add);
        setNum(h[i],dp[h[i]]);
        ans=max(ans,dp[h[i]]);
        
    }
    
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    //cin>>test;
    while(test--)
        aksayushx();
    return 0;
}
