#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define w(t) ll t;cin>>t; while(t--)
int main()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
string s,t;cin>>s>>t;
ll n=s.length(),m=t.length(),i,j;
ll dp[n+1][m+1];
//vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
for(i=0;i<=n;i++)
{
  for(j=0;j<=m;j++)
  {
       if(i==0 || j==0)
          dp[i][j]=0;
      else if(s[i-1]==t[j-1])
      dp[i][j]=dp[i-1][j-1]+1;
      else
      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      //cout<<dp[i][j]<<" ";
  }}
  //cout<<"\n";
  i=n,j=m;
  string ans="";
  while(i>0 && j>0)
  {
      if(dp[i][j]==dp[i-1][j])
      i-=1;
      else if(dp[i][j]==dp[i][j-1])
      j-=1;
      else
      {
          ans+=s[i-1];i-=1;j-=1;
      }
  }
  reverse(ans.begin(),ans.end());
  cout<<ans;
  
}
  