#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1003][20004];
int main() {
  ios::sync_with_stdio(false);
  // cin.tie(NULL);

  srand(time(NULL));

  int n;
  cin >> n;
  tuple<int,int,int> a[1003];
  for (int i = 1; i <= n; i++) {
    int w, s, v;
    cin >> w >> s >> v;
    a[i] = make_tuple(w, s, v);
  }

  sort(a + 1, a + n + 1, [](auto &x, auto &y){
    return get<0>(x) + get<1>(x) < get<0>(y) + get<1>(y);
  });

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 2e4; j++) {
      dp[i][j] = -1e18;
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int w, s, v;
    tie(w, s, v) = a[i];
    for (int j = 0; j <= 2e4; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= w && j - w <= s)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v);
    }
  }
  ll ans = 0;
  for (int i = 0; i <= 2e4; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << '\n';

  return 0;
}