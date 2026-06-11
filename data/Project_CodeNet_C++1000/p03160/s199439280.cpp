#include<bits/stdc++.h>
using namespace std;
int ans;
int frog(int *a, int i, int n,int *dp)
{
  //base condition
  if(i==n-1)
    return 0;
  if(dp[i]!=-1)
    return dp[i];
  if(i+1<=n-1)
  {
    ans = int(abs(a[i]-a[i+1])) + frog(a, i+1, n, dp);
  }
  if(i+2<=n-1)
  {
    ans  = min(ans, int(abs(a[i]-a[i+2])) + frog(a, i+2, n, dp));
  }
  return dp[i] =  ans;
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int dp[n+1];
  for(int i=0;i<=n;i++)
    dp[i]=-1;
  cout<<frog(a,0,n,dp)<<endl;
}
