#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

int main()
{
  string s; cin >> s;
  int n = s.length();
  vector<vector<ll>> dp(n+1, vector<ll>(4,0));

  dp[0][0] = 1;
  rep(i, n) {
    if (s[i] == '?') {
      rep(j, 4) dp[i+1][j] = dp[i][j]*3%mod;
      rep(j, 3) (dp[i+1][j+1] += dp[i][j]) %= mod;
    } else {
      int x = s[i]-'A';
      rep(j, 4) dp[i+1][j] = dp[i][j];
      (dp[i+1][x+1] += dp[i][x]) %= mod;
    }
  }
  cout << dp[n][3] << endl;

  return 0;
}
