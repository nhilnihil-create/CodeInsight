#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int i,j,n,m,dp[3003][3003];
  string s,t,str;
  cin>>s;
  cin>>t;
  n=s.size();
  m=t.size();
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=m;j++)
    {
      if(i==0 || j==0)
        dp[i][j]=0;
    }
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      if(s[i-1]==t[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
      else 
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  i=s.size();
  j=t.size();
  while(i>0 && j>0)
  {
    if(s[i-1]==t[j-1])
    {
    	 str.push_back(s[i-1]);
      i--;
      j--;
     
    }
    else 
    {
      if(dp[i][j-1]>dp[i-1][j])
        j--;
      else 
        i--;
    }
  }
  n=str.size();
  for(i=n-1;i>=0;i--)
    cout<<str[i];
  return 0;
}
      
        
      
        
