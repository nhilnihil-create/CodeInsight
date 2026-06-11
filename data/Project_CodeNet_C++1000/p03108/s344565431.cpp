#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l[100005],r[100005],ans[100005],fa[100005],cnt[100005];
ll get(ll x)
{
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(ll a,ll b)
{
    ll x = get(a),y = get(b);
    if(x != y)
    {
        cnt[y] += cnt[x];
        fa[x] = y;
    }

}
int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1; i<=m; i++)
    {
        scanf("%lld%lld",&l[i],&r[i]);
    }
    for(ll i=1; i<=n; i++)fa[i]=i;
    for(ll i=1; i<=n; i++)cnt[i]=1;
    ans[m]=n*(n-1)/2;
    for(ll i=m; i>=1; i--)
    {
        ll x=get(l[i]),y=get(r[i]);
        if(x==y)
        {
            ans[i-1]=ans[i];
            merge(x,y);
        }
        else
        {
            ans[i-1]=ans[i]-cnt[x]*cnt[y];
            merge(x,y);
        }
    }
    for(ll i=1;i<=m;i++)printf("%lld\n",ans[i]);
}
