#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  long long int dp[n][n], ps[n];
  ps[0]=a[0];
  for(int i=1;i<n;i++) ps[i]=ps[i-1]+a[i];
  for(int i=0;i<n;i++) dp[i][i]=0;
  for(int i=1;i<n;i++)
  {
    for(int j=0;j+i<n;j++)
    {
      dp[j][j+i]=INF;
      for(int k=j;k<j+i;k++)
      {
        dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]+ps[j+i]-((j>0)?ps[j-1]:0));
      }
    }
  }
  cout<<dp[0][n-1];
}