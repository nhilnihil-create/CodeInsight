#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int n;
string s;

void solve() {
  // dp[i][j]: after figure out the result for the first n number, how many of them end with j
  vector<vector<int> > dp(n, vector<int>(n));
  dp[0][0] = 1;
  for (int i=1; i<n; ++i) {
    char c = s[i-1];
    int count = 0;
    if (c == '>') {
      for (int j=i; ~j; --j) {
        dp[i][j] = count;
        if (j > 0) {
          count = (count + dp[i-1][j-1]) % MOD;
        }
      }
    } else {
      for (int j=0; j<=i; ++j) {
        dp[i][j] = count;
        count = (count + dp[i-1][j]) % MOD;
      }
    }
  }
  int res = 0;
  for (int i=0; i<n; ++i) {
    res = (res + dp[n-1][i]) % MOD;
  }
  cout << (res + MOD) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cin >> s;
  solve();
  return 0;
}