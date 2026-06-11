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
const int mod=1e9+7;
void solve()
{
  int n; cin>>n; int a[n][n];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
  int sz=pow(2,n);
  int dp[sz];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for(int mask=1;mask<sz;mask++)
  {
      int cnt=0;
      for(int i=0;i<n;i++)if(mask&(1<<i))cnt++;
      for(int i=0;i<n;i++)
      {
          int t=1<<i;
          if(mask&t)
          {
              if(!a[cnt-1][i])continue;
              dp[mask]+=dp[mask&(~t)];
              dp[mask]%=mod;
          }
      }

  }
  cout<<dp[sz-1];
  return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}
