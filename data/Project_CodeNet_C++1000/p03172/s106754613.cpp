#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
 long long int dp[n][k+1];
  for(int i=0;i<n;i++)
    dp[i][0]=1;
  vector<long int> c(n);
  int i,j,z;
  for(i=0;i<n;i++)
    cin>>c[i];
  sort(c.begin(),c.end());
  for(i=0;i<n;i++)
    for(j=1;j<k+1;j++)
      dp[i][j]=0;
  for(i=1;i<k+1;i++)
    if(i<=c[0])
      dp[0][i]=1;
  for(i=1;i<n;i++)
  {
    for(j=1;j<k+1;j++)
    {
      if(c[i]==0)
        continue;
      if(j==1)
        dp[i][j]=(dp[i-1][0]+dp[i-1][1])%mod;
      else if(j<=c[i])
        dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
      else if(dp[i][j-1]!=0){
        dp[i][j]=(dp[i][j-1]-dp[i-1][j-1-c[i]]+mod+dp[i-1][j])%mod;
      }
      else break;
    /* int  count=0;
      for(z=max(0,j-c[i]);z<=j;z++)
        count+=dp[i-1][z];
      dp[i][j]=count;*/
    }
  }
  cout<<dp[n-1][k]%mod;
  return 0;
}