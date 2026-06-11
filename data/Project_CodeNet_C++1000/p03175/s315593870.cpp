#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define flash ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
vector<ll> graph[1000000];ll mod=1e9+7;
pair<ll,ll> dfs(ll node,ll parent)
{
    ll a=1;ll b=1;
    for(auto x:graph[node])
    {
        
        if(x==parent)continue;
        pair<ll,ll> p=dfs(x,node);
        a=(a*p.second)%mod;
        b=b*(p.first+p.second)%mod;
        
    }
    pair<ll,ll> k;k.first=a;k.second=b;
    return k;
}
int main()
{
  ll n;cin>>n;
  for(ll i=1;i<=n-1;i++)
  {
      ll x;ll y;cin>>x>>y;
      graph[x].pb(y);
      graph[y].pb(x);
  }
  pair<ll,ll> x=dfs(1,-1);
  ll ans=(x.first+x.second)%mod;
  cout<<ans<<endl;
}
   
