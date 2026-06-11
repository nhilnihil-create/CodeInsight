#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MOD 1000000007

int main()
{
  string s;cin>>s;
  vector<vector<ll>> dp(3,vector<ll>(s.size()+1,0));
  int i;
  ll pat=1;
  for(i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='?')
    {
      dp[0][i]=(dp[0][i+1]*3+pat)%MOD;
      pat=(pat*3)%MOD;
    }
    else if(s[i]=='C')dp[0][i]=(dp[0][i+1]+pat)%MOD;
    else dp[0][i]=dp[0][i+1];
  }
  for(i=s.size()-2;i>=0;i--)
  {
    if(s[i]=='?')
    {
      dp[1][i]=(dp[1][i+1]*3+dp[0][i+1])%MOD;
    }
    else if(s[i]=='B')dp[1][i]=(dp[1][i+1]+dp[0][i+1])%MOD;
    else dp[1][i]=dp[1][i+1];
  }
  for(i=s.size()-3;i>=0;i--)
  {
    if(s[i]=='?')
    {
      dp[2][i]=(dp[2][i+1]*3+dp[1][i+1])%MOD;
    }
    else if(s[i]=='A')dp[2][i]=(dp[2][i+1]+dp[1][i+1])%MOD;
    else dp[2][i]=dp[2][i+1];
  }
  cout<<dp[2][0]<<endl;
}
