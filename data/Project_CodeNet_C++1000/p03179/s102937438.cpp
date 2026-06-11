#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long 
#define pb push_back
#define fo(i,N) for(int i = 0 ; i < N ; i++)
#define foo(i,x,N) for (int i = x; i < N ; i++)
#define fill(a,val) memset(a,val,sizeof(a))
#define fastio()  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define ff first
#define ss second
#define MAX 1234567
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define inf 1e14+1
#define all(a) a.begin(),a.end()
int n;
string s;
ll dp[3001][3001];

void solve()
{ 
  fill(dp,0);
  dp[n][0] = (s[n-2] == '>') ? 1 : 0;
  dp[n][1] = 1-dp[n][0];

  for(int i = n-1; i >= 2; i--)
  {
    int total = n-i+1;
    for(int j = 0 ; j <= total; j++)
    {
      if ( j == 0)
      {
         if ( s[i-2] == '<')
          continue;

        for(int k = 0; k<= total-1;k++)
        {
          dp[i][j] = (dp[i][j]+dp[i+1][k])%M;
        }
      }
      else
      {
        if ( s[i-2] == '<')
        {
          dp[i][j] = (dp[i][j-1] + dp[i+1][j-1])%M;
        }
        else
          dp[i][j] = (M+dp[i][j-1] - dp[i+1][j-1])%M;
      }
    }
  }
}


int main()
{ 
  cin >> n >> s;

  ll ans = 0;
  solve();
  fo(i,n)
  {
    ans = (ans+dp[2][i])%M;
  }
  cout << ans << endl;

}