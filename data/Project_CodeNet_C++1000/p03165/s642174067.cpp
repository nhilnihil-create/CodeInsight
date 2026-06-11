#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int main()
{
  string s,t;
  cin>>s>>t;
  int n=s.size();
  int m=t.size();
  if(n>m)
  {
    string temp=s;
    s=t;
    t=temp;
    int sw=n;
    n=m;
    m=sw;
  }
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s[i-1]==t[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
      else
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  string ans="";
  int i=n,j=m;
  while(i>0&&j>0)
  {
    if(s[i-1]==t[j-1])
    {
      ans=s[i-1]+ans;
      i--;
      j--;
    }
    else
    {
      if(dp[i-1][j]>dp[i][j-1])
        i--;
      else
        j--;
    }
  }
  cout<<ans<<endl;
}
