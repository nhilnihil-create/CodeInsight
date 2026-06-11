#include<iostream>
#include<vector>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
const long long int m = 1000000007;

int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
  dp[1][1] = 1;
  vector<vector<ll>> prefix(n+1,vector<ll>(n+1,0));
  prefix[1][1] = 1;
  for(int i = 0 ; i < n-1 ; i++ )
  {
    for(int j = 1; j <= i+2; j++ )
    {
      if(s[i]=='>'){
        dp[i+2][j] = prefix[i+1][i+1] - prefix[i+1][j-1];
        if(dp[i+2][j]<0)dp[i+2][j]+=m;
      }
      if(s[i]=='<'){
        dp[i+2][j] = prefix[i+1][j-1];
      }
      prefix[i+2][j] = (prefix[i+2][j-1] + dp[i+2][j])%m;
    }
  }
  cout<<prefix[n][n]<<"\n";
  return 0;
}
