#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int maxn = 3e3 + 3;
ll dp[maxn][maxn];
string s;

int main() {
  ios::sync_with_stdio(false);
  // cin.tie(NULL);

  int n;
  cin >> n >> s;
  s = "." + s;
  dp[n][1] = 1;
  int len = 1;
  for (int i = n - 1; i >= 1; i--) {
    len++;
    if (s[i] == '>') {
      ll sum = dp[i + 1][1];
      for (int j = 2; j <= len; j++) {
        dp[i][j] = sum;
        sum = (sum + dp[i + 1][j]) % mod;
      }
    } else {
      ll sum = dp[i + 1][len - 1];
      for (int j = len - 1; j >= 0; j--) {
        dp[i][j] = sum;
        sum = (sum + dp[i + 1][j - 1]) % mod;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[1][i]) % mod;
  }
  cout << ans << '\n';

  return 0;
}