#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
vector<vector<ll>> gr(1e5+2);
vector<vector<ll>> dp(1e5+2,vector<ll>(2,-1));
ll solve(int node,bool x,int p)
{
  if(dp[node][x]!=-1)
  return dp[node][x];
  ll ans=1,ans2=1;
  if(gr[node].size()==1&&p==gr[node][0])
  return dp[node][x]=(x==0?2:1);
  for(int z: gr[node])
  {
    if(z==p)
    continue;
    if(x)
    ans=(ans*solve(z,0,node))%mod;
    else
    {
      ans=(ans*solve(z,0,node))%mod;
      ans2=(ans2*solve(z,1,node))%mod;
    }
  }
  if(x)
  return dp[node][x]=(ans%mod);

  return dp[node][x]=((ans+ans2)%mod);
} 
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<n;i++)
  {
     int x,y;
     cin>>x>>y;
     gr[x].push_back(y);
     gr[y].push_back(x);
  }
  ll ans=(solve(1,0,-1)%mod);
  cout<<ans<<endl;
  return 0;
}