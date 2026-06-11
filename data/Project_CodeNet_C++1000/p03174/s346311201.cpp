#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[21][2100000];
int done;
int n;
int a[21][21];
int d[21];
int solve(int rowmask,int i)
{
      if(rowmask==done&&i==n)
      return 1;
      if(dp[i][rowmask]!=-1)
      return dp[i][rowmask];
      int safe = d[i]&(~rowmask);
      int ans = 0;
      while(safe)
      {
          int p = safe&(-safe);
          safe = safe-p;
          ans = (ans%mod+solve(rowmask|p,i+1)%mod)%mod;
      }
      return dp[i][rowmask] = ans;    
}
int main() {
    cin>>n;
    done = (1<<n)-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        int tem=1;
        int ans= 0;
        for(int j=n-1;j>=0;j--)
        {
           ans+=tem*a[i][j];
           tem*=2;
        }
        d[i] = ans;
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0);
}
