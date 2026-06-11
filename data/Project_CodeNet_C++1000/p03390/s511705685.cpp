#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
ll k_th(ll x,ll y)
{
    if(y<x) return  y;
    return y+1;
}
bool judge(ll m)
{
    ll k=m/2;
    for(ll i=max(1ll,k-1);i<=min(k+1,m);i++)
        if(k_th(a,i)*k_th(b,m-i+1)>=a*b) return false;
    return true;
}
int main()
{
    int q;scanf("%d",&q);
    while(q--)
    {
        scanf("%lld%lld",&a,&b);
        ll l=0,r=2e9,ans;
        while(l<=r)
        {
            ll m=l+r>>1;
            if(judge(m)) ans=m,l=m+1;
            else r=m-1;
        }
        printf("%lld\n",ans);
    }
}
