#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;

int n;
string s;
ll dp[3001][3001];
void solve()
{
  dp[n][0]=(s[n-2]=='>')?1:0;
  dp[n][1]=(s[n-2]=='<')?1:0;
  for(int i=n-1;i>=2;i--)
  {
    int total=n-i+1;
    for(int g=0;g<=total;g++)
    {
      if(g==0)
      {
        dp[i][g]=0;
        if(s[i-2]=='<')
        continue;
        //s=total-g=total-0=total
        for(int j=1;j<=total;j++)
        dp[i][g]=(dp[i][g]+dp[i+1][total-j])%mod;
      }
      else
      {
        if(s[i-2]=='>')
        dp[i][g]=(mod+dp[i][g-1]-dp[i+1][g-1])%mod;
        else
        dp[i][g]=(mod+dp[i][g-1]+dp[i+1][g-1])%mod;
      }
    }
  }
}
int main()
{
  cin>>n;
  cin>>s;
  solve();
  ll ans=0;
  for(int gr=n-1;gr>=0;gr--)
    ans=(ans+dp[2][gr])%mod;
  cout<<ans<<endl;
  return 0;
}
