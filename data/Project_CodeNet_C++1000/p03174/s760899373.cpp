#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
vector<vector<int>> v;
vector<vector<ll>> dp;
int siz,n;
ll solve(int i,int x)
{
  if(i==n)
  return (x==0?1:0);
  if(dp[i][x]!=-1)
  return dp[i][x];
  ll ans=0;
  for(int j=0;j<n;j++)
  {
    if(v[i][j]==0||(((1<<j)&x)==0))
    continue;
    ans=(ans+solve(i+1,(x^(1<<j))))%mod;
  }
  return dp[i][x]=ans;
}
int main()
{
  cin>>n;
  v.resize(n,vector<int>(n));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>v[i][j];
    }
  }
  siz=(1<<n)-1;
  dp.resize(n,vector<ll>((1<<n),-1));
  cout<<solve(0,siz)<<endl;
  return 0;
}
