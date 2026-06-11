#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> c(10, vector<int>(10));
  rep(i, 10) rep(j, 10) cin >> c.at(i).at(j);
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  // ワーシャルフロイド法で各数字間のコスト(魔力)を計算
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        c.at(i).at(j) = min(c.at(i).at(j), c.at(i).at(k) + c.at(k).at(j));
      }
    }
  }
  // 計算したコストから置き換えに必要な値を計算
  int res = 0;
  rep(i, h) rep(j, w) {
      int aa = a.at(i).at(j);
      if (aa == -1) {
        continue;
      }
      res += c.at(aa).at(1);
    }
  cout << res << endl;
  return 0;
}
