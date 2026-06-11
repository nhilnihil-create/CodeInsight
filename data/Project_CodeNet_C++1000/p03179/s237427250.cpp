#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INTF = 1e9 + 7;

int dp[3005][3005];
int pre[3005];

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  dp[1][1] = 1;

  for(int i=1; i<=n; i++)
    pre[i] = (pre[i-1] + dp[1][i])%INTF;

  for(int i=2; i<=n; i++)   
  {
    for(int j=1; j<=i; j++)  
    {
      int L, R;
      if(s[i-2] == '<')
      {
        L = 1, R= j-1;
      }
      else
      {
        L = j, R= i-1;
      }

      dp[i][j] = (1ll*dp[i][j] + 1ll*pre[R] - 1ll*pre[L-1] + INTF)%(1ll*INTF);
    }
    for(int k=1; k<=n; k++)
      pre[k] = (1ll*pre[k-1] + 1ll*dp[i][k])%(1ll*INTF);
  }

  int ans = 0;
  for(int i=1; i<=n; i++)
    ans = (1ll*ans + 1ll*dp[n][i])%(1ll*INTF);

  cout<<ans;
  return 0;
}
