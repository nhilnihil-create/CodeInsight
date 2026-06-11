#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;

int n;
vector<vector<ll>> sc;
ll dp[(1<<16)];
ll sums[(1<<16)];
ll calc(int mask)
{
  ll ans=0;
  for(int i=0;i<16;i++)
  {
    for(int j=i+1;j<16;j++)
    {
      if((mask&(1<<i))&&(mask&(1<<j)))
        ans+=sc[i][j];
    }
  }
  return ans;
}
void sumcalc(int n)
{
  for(int i=1;i<(1<<n);i++)
  {
    sums[i]=calc(i);
  }
}
ll solve(int mask)
{
  if(mask==0)
  return 0;
  if(dp[mask]!=-1)
  return dp[mask];
  ll ans=0;
  for(int sub=mask;sub!=0;sub=(sub-1)&mask)
  {
    ans=max(ans,sums[sub]+(solve(mask^sub)));
  }
  return dp[mask]=ans;
}
int main()
{
  memset(dp,-1,sizeof(dp));
  cin>>n;
  sc.resize(n,vector<ll>(n));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      cin>>sc[i][j];
  }
  sumcalc(n);
  cout<<solve((1<<n)-1)<<endl;
  return 0;
}
