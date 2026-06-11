#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less   
using namespace __gnu_pbds;  
using namespace std;  
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> set1;
ll find(ll a,ll p[])
{
   //cout<<"find "<<a<<endl;
   if(a==p[a])
   return a;
   else return p[a]=find(p[a],p);

}
void join(ll a,ll b,ll p[],ll sz[])
{
   a=find(a,p);
   b=find(b,p);
   if(a!=b)
   {
      if(sz[a]<sz[b])
      swap(a,b);
      sz[a]+=sz[b];
      p[b]=a;
   }
}
ll power(ll a,ll b,ll mod)
{
   ll res=1;
   while(b>0)
   {
      if(b&1)
      res=(res*a)%mod;
      b=b/2;
      a=(a*a)%mod;
   }
   return res;
}
ll inverse(ll x, ll p)
{
   return power(x,p-2,p);
}
ll hash1(ll x,ll y)
{
   return x+y+x*y;
}
//ll f[200000]={0};
ll mod=1000000007;
/*void ini()
{
   f[0]=1;
   for(ll i=1;i<=200000;i++)
   f[i]=(i*f[i-1])%mod;
}*/



/*ll ncr(ll n,ll r)
{
   ll res=1;
   ll k=f[n];
   ll v=inverse(f[n-r],mod);
   ll u=inverse(f[r],mod);
   ll x=(u*v)%mod;
   k=(k*x)%mod;
   return k;
}*/
/*struct edge
{
   ll from;
   ll to;
};*/
void dfs(ll v,ll vis[],ll dp[][2],vector<ll> adj[])
{
   ll k=adj[v].size();
   dp[v][1]=1;
   dp[v][0]=1;
   for(ll i=0;i<k;i++)
   {
      ll u=adj[v].at(i);
      if(vis[u]==0)
      {
         vis[u]=1;
         dfs(u,vis,dp,adj);
         dp[v][0]=(dp[v][0]*(dp[u][1]+dp[u][0]))%mod;
         dp[v][1]=((dp[v][1])*(dp[u][0]))%mod;
         
      }
      
      
   }
}


int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
   vector<ll> adj[n+1];
   for(ll i=0;i<n-1;i++)
   {
      ll u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
   }
   ll dp[n+1][2];
   for(ll i=0;i<=n;i++)
   dp[i][0]=dp[i][1]=0;
   ll vis[n+1]={0};
   vis[1]=1;
   dfs(1,vis,dp,adj);
   ll ans=(dp[1][1]+dp[1][0])%mod;
   cout<<ans<<endl;
   return 0;
}
