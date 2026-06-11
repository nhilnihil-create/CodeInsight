#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main()
{
  int n, k;
  cin>>n>>k;
  int a[n+1];
  for(int i=1;i<=n;i++) cin>>a[i];
  long long int dp[n+1][k+1];
  for(int i=0;i<=n;i++) dp[i][0]=1;
  for(int j=1;j<=k;j++) dp[0][j]=1;
  for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) dp[i][j]=(dp[i][j-1]+dp[i-1][j]-((j>a[i])?dp[i-1][j-a[i]-1]:0))%mod;
  cout<<(dp[n][k]-((k>0)?dp[n][k-1]:0)+mod)%mod;
}