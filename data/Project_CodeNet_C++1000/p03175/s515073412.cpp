#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
vector<ll> v[100005];
ll dp[100005][2];
ll sol(ll src,ll constrall,ll parent)
{
    if(dp[src][constrall]!=-1)
        return dp[src][constrall];
    ll ans=0;
    ll w1=1;
    for(auto child:v[src])
    {
        if(child!=parent)
            w1=(w1*sol(child,0,src))%mod;
    }
    ans+=w1;
    if(!constrall)
    {
        ll w2=1;
    for(auto child:v[src])
    {
        if(child!=parent)
            w2=(w2*sol(child,1,src))%mod;
    }
    ans=(ans+w2)%mod;
    }
    return dp[src][constrall]=ans;

}
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    ll ans=sol(1,0,-1);
    cout<<ans<<endl;
    return 0;
}
