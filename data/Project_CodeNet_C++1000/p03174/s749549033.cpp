#include <bits/stdc++.h>
using namespace std;
#define ll long long
int  M = 1e9+7;
int a[22][22];
int n;
ll dp[21][(1<<21)-1];
ll solve(int i,ll bitmask)
{
  //cout<<i<<" "<<bitmask<<endl;
  if(i==n) return 1;
  if(dp[i][bitmask]!=-1) return dp[i][bitmask];
  ll ans = 0;
  for(int j=0;j<n;j++)
  {
    if(a[i][n-j-1] == 1 && bitmask&(1<<j))
    {
      ans = (ans+solve(i+1,bitmask-(1<<j)))%M;
    }
  }
  dp[i][bitmask] = ans;
  return ans;
}
int main() {
  for(int i=0;i<21;i++)
  {
    for(int j=0;j<(1<<21)-1;j++)
    {
      dp[i][j]=-1;
    }
  }
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  cout<<solve(0,(1<<n)-1);
  return 0;
}