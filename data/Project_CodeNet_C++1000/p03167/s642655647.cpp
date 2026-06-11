#include<iostream>
using namespace std;
#define ll long long 
#include<bits/stdc++.h>
#define mod 1000000007
void grid(ll int n,ll int m,string s[])
{
  ll int dp[n+1][m+1];
  memset(dp, 0, sizeof(dp)); 
  int f=0;
  
  for(int i=0;i<m;i++)
  {
     if(s[0][i]=='#')
     f=1;
     if(f==0)
      dp[0][i]=1;
  }
  
  f=0;
  for(int i=0;i<n;i++)
  {
     if(s[i][0]=='#')
     f=1;
    if(f==0)
      dp[i][0]=1;
   }
  
  for(ll int i=1;i<n;i++)
  {
    for(ll int j=1;j<m;j++)
    {
      if(s[i][j]=='#')
        dp[i][j] = 0;
      else
        dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
    }
  }
  cout<<dp[n-1][m-1]%mod<<endl;

}
int main()
{
 	ll int n,m;
  cin>>n>>m;
  string s[n];
  for(ll int i=0;i<n;i++)
    cin>>s[i];
  grid(n,m,s);
}
