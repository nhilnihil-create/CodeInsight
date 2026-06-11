#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define inf 1e18+5
using namespace std;
void solve()
{
  int n; cin>>n; int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  int dp[n][n],el[n][n];
  for(int i=0;i<n;i++)
  {
      for(int j=0;j+i<n;j++)
      {
          if(!i){dp[j][j]=0; el[j][j]=a[j]; continue;}
          dp[j][j+i]=inf;
          for(int k=j;k<j+i;k++)
          {
              if(dp[j][k]+dp[k+1][j+i]+el[j][k]+el[k+1][j+i]<dp[j][j+i])
              {
                  dp[j][j+i]=dp[j][k]+dp[k+1][j+i]+el[j][k]+el[k+1][j+i];
                  el[j][j+i]=el[j][k]+el[k+1][j+i];
              }
          }
      }
  }
  cout<<dp[0][n-1];
  return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; t=1;
    while(t--)solve();
    return 0;
}
