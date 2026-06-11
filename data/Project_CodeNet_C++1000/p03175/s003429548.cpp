#include<bits/stdc++.h>
#define Mx 1000000000005 
#define ll long long  
#define pi 3.141592653
#define vi vector<ll>
#define Mo 1000000007
#define mp make_pair
#define M map<ll,ll>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define vii vector<pair<ll,ll> > 
#define fi first
#define se second
#define pb push_back
#define ld long double
#define fill(a,x) memset(a,x,sizeof(a))
using namespace std;
bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
  return a.second<b.second;
}
/*vi b=v;
   sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  ll t; cin>>t; fr(f,0,t){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 */
vector<vector<ll>> dp(1e5 + 2, vector<ll>(2,-1));
ll func(vi v[],ll s,bool vis[],ll c)
{ 
  if(dp[s][c]!=-1) return dp[s][c];

  ll ans=1,x;
  vis[s]=1;
  fr(i,0,v[s].size())
  {
    if(!vis[v[s][i]])
    { 
      if(c==0)
        x=func(v,v[s][i],vis,c)+func(v,v[s][i],vis,(c+1)%2);
      else 
        x=func(v,v[s][i],vis,(c+1)%2);
      x%=Mo;
      ans*=x; ans%=Mo;
    }
  }
  vis[s]=0;
  return dp[s][c]=ans;
}
int main()
{
  ll V,x,y; cin>>V;
  vi v[V+1];
  fr(i,0,V-1)
  {
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }

  bool vis[V+1]={0};
  ll ans=(func(v,V,vis,0)+func(v,V,vis,1))%Mo;
  cout<<ans;


}
