#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      dp[i + 1][j] += dp[i][j];
      if (j < 3 && s[i] == "DMC"[j]) dp[i + 1][j + 1] += dp[i][j];
    }
  }
  vector<int> csm(n + 1, 0);
  for (int i = 0; i < n; i++) {
    csm[i + 1] = csm[i] + (s[i] == 'M');
  }
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    ll ans = dp[n][3];
    for (int j = k; j <= n; j++) {
      if (s[j - 1] != 'C') continue;
      ans -= dp[j - k][2];
      ans -= dp[j - k][1] * (csm[j] - csm[j - k]);
    }
    cout << ans << endl;
  }
}
