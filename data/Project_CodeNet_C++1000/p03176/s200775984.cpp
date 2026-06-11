#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb emplace_back
#define all(c)  c.begin(), c.end()
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vp vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define lb "\n"
#define rep(i,a,b) for(ll i = a;i<b;i++)
#define INF 1000000007
#define MAX LLONG_MAX
#define maxn 200001
ll max(ll x,ll y){if(x>y)return x;else return y;}
ll min(ll x,ll y){if(x>y)return y;else return x;}
ll t[4*maxn];
/*void build(int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else
    {
        int tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        t[v]=max(t[2*v],t[2*v+1]);
    }
}*/
ll query(ll v, ll tl,ll tr, ll l,ll r)
{
    if(l>r)
        return -INF;
    if(l==tl&&r==tr)
        return t[v];
    ll tm=(tl+tr)/2;
    return max(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
}
void update(ll v,ll tl, ll tr, ll pos,ll value)
{
    if(tl==tr)
        t[v]=value;
        else{
    ll tm=(tl+tr)/2;
    if(pos<=tm)
        update(2*v,tl,tm,pos,value);
    else
        update(2*v+1,tm+1,tr,pos,value);
    t[v]=max(t[2*v],t[2*v+1]);}
}
ll dp[200001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
ll i,j,k,n,m,ans=0;
cin>>n;
vll h(n),a(n);
rep(i,0,n)
cin>>h[i];
rep(i,0,n)
cin>>a[i];
rep(i,0,n)
{
   dp[i]=query(1,0,n,0,h[i]-1)+a[i];
   update(1,0,n,h[i],dp[i]);
}
rep(i,0,n)
ans=max(ans,dp[i]);
cout<<ans;
return 0;
}
