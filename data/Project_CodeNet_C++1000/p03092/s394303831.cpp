#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 5007;

ll dp[N][N];

const ll Inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, a, b;
  cin >> n >> a >> b;
  vector <int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = Inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] == Inf) continue;
      if (p[i] < j) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b);
      } else {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a);
        dp[i + 1][p[i]] = min(dp[i + 1][p[i]], dp[i][j]);
      }
    }
  }
  ll ans = Inf;
  for (int i = 0; i <= n; ++i) ans = min(ans, dp[n][i]);
  cout << ans << '\n';
}

