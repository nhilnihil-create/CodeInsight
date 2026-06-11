#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define int long long

const int N = 55;

int dp[N][2];
int cnt[N][2];

signed main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  for (int i = 0; i < n; i++) {
    int x = a[i];
    for (int j = 0; j < N; j++) {
      cnt[j][(x >> j) & 1]++;
    }
  }

  memset(dp, -1, sizeof(dp));
  dp[50][0] = 0;

  for (int i = 49; i >= 0; i--) {
    bool bit = false;
    if((k >> i) & 1) bit = true;

    int x = (1LL << i) * cnt[i][0];
    int y = (1LL << i) * cnt[i][1];

    // tight -> tight
    if(dp[i + 1][0] != -1) {
      if(bit) chmax(dp[i][0], dp[i + 1][0] + x);
      else chmax(dp[i][0], dp[i + 1][0] + y);
    }

    // tight -> loose
    if(dp[i + 1][0] != -1) {
      if(bit) chmax(dp[i][1], dp[i + 1][0] + y);
    }

    // loose -> loose
    if(dp[i + 1][1] != -1) {
      chmax(dp[i][1], dp[i + 1][1] + x);
      chmax(dp[i][1], dp[i + 1][1] + y);
    }
  }

  int ans = max(dp[0][1], dp[0][0]);
  cout << ans << '\n';
}
