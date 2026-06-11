#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;

int dp[3005][3005];

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(0);   
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif

  int n;
  cin>>n;
  string s;
  cin>>s;
  s="#"+s;
  for(int i=0;i<n;i++)
  {
    dp[1][i]=1;
  }
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i]=='<')
      {
          dp[i+1][0]+=dp[i][j];
          dp[i+1][0]%=mod;
          dp[i+1][j]-=dp[i][j]-mod;
          dp[i+1][j]%=mod;
      }
      else
      {
        int z=(n-i);
        dp[i+1][j]+=dp[i][j];
        dp[i+1][j]%=mod;
        dp[i+1][z]-=dp[i][j]-mod;
        dp[i+1][z]%=mod;
      }
    }
    for(int j=1;j<n;j++)
    {
      dp[i+1][j]=(dp[i+1][j]+dp[i+1][j-1])%mod;
    }
  }
  cout<<dp[n][0];

}