#include <bits/stdc++.h>

using namespace std;

char cmp[3003];
int dp[3003][3003], pref[3003][3003];

const int mod = 1e9 + 7;

void add_self (int& a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
}

int main() {
  int n;
  cin >> n >> cmp;
  dp[1][1] = 1;
  for (int len = 2; len <= n; ++len) {
    for (int i = 1; i < len; ++i)
      pref[len - 1][i] = (pref[len - 1][i - 1] + dp[len - 1][i]) % mod;
    for (int b = 1; b <= len; ++b) {
      int L, R;
      if (cmp[len - 2] == '<')
        L = 1, R = b - 1;
      else
        L = b, R = len - 1;
      if (L <= R)
        add_self (dp[len][b], (pref[len - 1][R] - pref[len - 1][L - 1] + mod) % mod);
    }
  }
  int ans = 0;
  for (int b = 1; b <= n; ++b)
    add_self (ans, dp[n][b]);
  cout << ans;
}