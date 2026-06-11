#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 

ll  dp[22][(1<<22)];
ll mod = 1e9+7;
//int matching[21][21];
ll solve(int i,int mask,int n,vector<vector<ll>>& matching)
{
  if(i==n+1)
  {
      if(mask==0)
      return 1;
      return 0;
  }
  if(dp[i][mask]!=-1) return dp[i][mask];
  ll answer=0;
 // dp[i][mask]=0;
  for(int j=0;j<n;j++)
  {
    bool isavail =  ((mask & (1<<j)) != 0 )?1:0;
    if(matching[i][j+1]&&isavail)
    {
        //flag=1;
      answer+=(solve(i+1,mask^(1<<(j)),n,matching));
      answer%=mod;
    }
  }
 // if(flag==0)
//  return 0;
  return dp[i][mask]=answer;
}
int main()
{
    fast_io;
  ll n;
  cin>>n;
  vector<vector<ll>> matching(n+1,vector<ll>(n+1,0)) ;
  int i,j;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      cin>>matching[i][j];
  memset(dp,-1,sizeof(dp));
  cout<<solve(1,(1<<n)-1,n,matching)%mod;
  
}