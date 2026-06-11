#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int i,j,n=s.size(),m=t.size();
    int dp[n+1][m+1];
    mem(dp,0);
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=m;j++)
      {
        if(i==0||j==0)
        dp[i][j]=0;
        else if(s[i-1]==t[j-1])
        dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
    // cout<<dp[n][m];
    int len=dp[n][m];
    string ans;
    while(len>0)
    {
      if(s[n-1]==t[m-1])
      {
        ans+=s[n-1];
        len--;
        n--;
        m--;
      }
      else if(dp[n-1][m]>dp[n][m-1])
      n--;
      else
      m--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}