#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9+7;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  
  vector<vector<int>> dp(h, vector<int>(w, 0));
  dp[0][0] = 1;
  rep(i, h) rep(j, w) {
    if (a[i][j] == '#') continue;
    if (i) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
    if (j) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
  }
  cout << dp[h-1][w-1] << endl;
  return 0;
}