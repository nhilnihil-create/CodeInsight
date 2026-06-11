#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10, M = 2e4 + 10;
ll dp[N][M + 1];
int main() {
  ios::sync_with_stdio(false);
  // cin.tie(NULL);

  int n;
  cin >> n;
  tuple<int,int,int> a[N];
  for (int i = 1; i <= n; i++) {
    int w, s, v;
    cin >> w >> s >> v;
    a[i] = make_tuple(w, s, v);
  }
  sort(a + 1, a + n + 1, [](auto &x, auto &y){
    return get<0>(x) + get<1>(x) < get<0>(y) + get<1>(y);
  });
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= M; j++) {
      dp[i][j] = -1e18;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int w, s, v;
    tie(w, s, v) = a[i];
    for (int j = 0; j <= M; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= w && j - w <= s)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v);
    }
  }
  ll ans = 0;
  for (int i = 0; i <= M; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << '\n';

  return 0;
}
