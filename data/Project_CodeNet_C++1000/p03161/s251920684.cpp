#include<bits/stdc++.h>
using namespace std;

int frog(int i , int*a ,int n, int k,int *dp)
{
  if(i==n-1)
    return 0;
  int maxi = INT_MAX;
  if(dp[i]!=-1)
  return dp[i];
  for(int j=1;j<=k;j++)
  {
    if(i+j>=n)
      break;
    maxi = min(maxi, int(abs(a[i]-a[i+j])) + frog(i+j, a ,n,k,dp));
  }
  return dp[i] = maxi;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],dp[n+1];
    for(int i=0;i<=n;i++)
    dp[i]=-1;
    for(int i=0;i<n;i++)
    cin>>a[i];

   cout<<frog(0,a,n,k,dp);
}
