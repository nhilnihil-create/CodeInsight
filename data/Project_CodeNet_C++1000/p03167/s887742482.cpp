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
    int n,m,i,j;
    cin>>n>>m;
    char a[n][m];
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        cin>>a[i][j];

    int dp[n+1][m+1],f=0;
    for(i=0;i<n;i++)
    {
      if(a[i][0]=='.' && f==0)
      dp[i][0]=1;
      else
      {
        f=1;
        dp[i][0]=0;
      }
    }
    f=0;
    for(i=0;i<m;i++)
    {
      if(a[0][i]=='.' && f==0)
      dp[0][i]=1;
      else
      {
        f=1;
        dp[0][i]=0;
      }
    }
    for(i=1;i<n;i++)
    {
      for(j=1;j<m;j++)
      {
        if(a[i][j]=='#')
        dp[i][j]=0;
        else
        dp[i][j]=(dp[i-1][j]%MOD+dp[i][j-1]%MOD)%MOD;
      }
    }
    cout<<dp[n-1][m-1]%MOD;
    return 0;
}