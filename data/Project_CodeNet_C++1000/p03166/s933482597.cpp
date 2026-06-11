#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#define ios   ios_base::sync_with_stdio(false);  cin.tie(0);    cout.tie(0);
typedef   long long int ll;
using namespace std;
const int N=1e5+5;
#define fi first
#define se second
#define pb push_back
#define endl "\n"
ll n,m;
vector<ll> adj[N];
ll cnt[N];
ll ans;
ll dfs(ll u)
{
    ll &g=cnt[u];
    if(g!=-1)
    return g;
    g=0;
    for(auto f : adj[u])
    {
        g=max(g,dfs(f)+1);
    }
    return g;
}
int main()
{
   cin>>n>>m;
   for(ll i=1;i<=n;++i)
   cnt[i]=-1;
   for(ll i=0;i<m;++i)
   {
       ll u,v;cin>>u>>v;
       adj[u].pb(v);
       //adj[v].pb(u);
   }
   for(ll i=1;i<=n;++i)
   {
       if(cnt[i]==-1)
       {
           ans=max(ans,dfs(i));
       }
   }
   //cout<<endl;
   //for(ll i=1;i<=n;++i)
   //cout<<cnt[i]<<" ";
   cout<<ans;
}