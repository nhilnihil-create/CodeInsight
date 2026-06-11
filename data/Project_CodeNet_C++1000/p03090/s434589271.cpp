#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n;
  cin >> n;

  // 完全グラフから辺を除く方針で。
  // 完全グラフの場合。頂点iのスコアはn * (n + 1) / 2 - i
  // 除くべき片
  // 1 - n - 1
  // 2 - n - 2
  // ...
  // 偶数の場合はこれでおｋ
  // 奇数の場合はペアが作れないやつがいるけど。。。

  int m = n - n % 2;
  vector<pair<int, int>> ans;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      if (j == m - i - 1) continue;
      ans.emplace_back(i, j);
    }
  }
  if (n % 2 == 1)
    for (int i = 0; i < m; ++i) ans.emplace_back(i, m);

  cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); ++i)
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
  return 0;
}