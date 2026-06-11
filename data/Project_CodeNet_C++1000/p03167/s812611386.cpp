#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int mod = 1e9+7;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  vector<vector<int>> dp(h, vector<int>(w));
  dp[0][0] = 1;
  rep(i,h) rep(j,w) {
    if(i+1 < h && s[i+1][j] == '.') dp[i+1][j] += dp[i][j] % mod;
    if(j+1 < w && s[i][j+1] == '.') dp[i][j+1] += dp[i][j] % mod;
  }
  int ans = dp[h-1][w-1] % mod;
  cout << ans << endl;
  return 0;
}
