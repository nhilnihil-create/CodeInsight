#include<bits/stdc++.h>
#define l long 
#define ll long long 
#define ld long double 
#define INF 1000000000000000
#define MOD 1000000007
#define MAX_N 1000006
#define f first
#define s second
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULLL);
using namespace std;
vector<ll> tree(MAX_N);
vector<ll> dp(MAX_N);
void build(l v,l tl,l tr)
{
    if(tl==tr)
    {
        tree[v]=dp[tl];
        return;
    }
    l tm=(tl+tr)>>1;
    build(2L*v,tl,tm);
    build(2L*v+1,tm+1,tr);
    tree[v]=max(tree[2L*v],tree[2L*v+1]);
    return;
}
void update(ll val,l pos,l v,l tl,l tr)
{
    if(tl==tr)
    {
        tree[v]=val;
        dp[pos]=val;
        return;
    }
    l tm=(tl+tr)>>1;
    if(pos<=tm)
    update(val,pos,2L*v,tl,tm);
    else 
    update(val,pos,2L*v+1,tm+1,tr);
    tree[v]=max(tree[2L*v],tree[2L*v+1]);
    return;
}
ll rng_max(l lo,l hi,l v,l tl,l tr)
{
    if(lo>hi)
    return -1;
    if(lo==tl&&hi==tr)
    return tree[v];
    l tm=(tl+tr)>>1;
    return max(rng_max(lo,min(hi,tm),2L*v,tl,tm),rng_max(max(lo,tm+1),hi,2L*v+1,tm+1,tr));
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    l n,x;
    cin>>n;
    vector<l> h;
    vector<ll> a;
    ll val;
    for(l i=0;i<n;i++)
    {
        cin>>x;
        h.push_back(x);
    }
    for(l i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    build(1L,0L,n);
    ll ans=0;
    for(l i=0;i<n;i++)
    {
        if(i==0)
        {
            update(a[i],h[i],1L,0L,n);
        }
        else 
        {
            val=rng_max(0L,h[i]-1,1L,0L,n);
            update(val+a[i],h[i],1L,0L,n);
        }
        ans=max(ans,dp[h[i]]);
    }
    cout<<ans<<endl;
}