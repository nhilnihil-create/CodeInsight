#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define ll long long
#define pii pair < int, int >
#define fr first
#define sc second
#define mk make_pair

const int N = (int)3e2 + 7;
const int inf = (int)1e9 + 7;

int dp[N][N][N];

main() {
  string s;
  cin >> s;
  int n = s.size();
  int k;
  scanf("%d", &k);
  for (int l = n - 1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      for (int i = 0; i <= k; i++) {
        if (l == r) {
          dp[l][r][i] = 1;
          continue;
        }
        if (l + 1 == r) {
          dp[l][r][i] = (s[l] == s[r] || i > 0) ? 2 : 1;
          continue;
        }
        dp[l][r][i] = max(dp[l + 1][r][i], dp[l][r - 1][i]);
        if (s[l] == s[r]) {
          dp[l][r][i] = max(dp[l][r][i], dp[l + 1][r - 1][i] + 2);
        }
        if (i > 0) {
          dp[l][r][i] = max(dp[l][r][i], dp[l + 1][r - 1][i - 1] + 2);
        }
      }
    }
  }
  cout << dp[0][n - 1][k];
}
