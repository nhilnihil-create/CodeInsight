// https://atcoder.jp/contests/abc104/tasks/abc104_c
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000  // 1e9
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define print(x) cout << x << endl;

int main() {
  int D, G;
  cin >> D >> G;

  vector<int> p(D), c(D);
  rep(i, D) cin >> p.at(i) >> c.at(i);

  int ans = INF;
  rep(bit, 1 << D) {
    int curr = 0, amt = 0;

    rep(i, D) if (bit & (1 << i)) {
      curr += p.at(i);
      amt += (i + 1) * 100 * p.at(i) + c.at(i);
    }
    // 100i 点問題を完答するかどうかでbit全探索
    // この時点で val が規定値を超えていてcnt が一番小さい場合
    // or valが規定値を超えていないがcntがそれより下回る場合の２択
    if (G <= amt) {
      ans = min(ans, curr);
    } else {
      // 完答しないケースにおいて配点の大きいものから解いていく。
      for (int i = D - 1; i >= 0; i--) {
        // 完答するケースをのぞく
        if (bit & (1 << i)) continue;
        bool flag = false;

        rep(j, p.at(i) - 1) {
          if (flag) break;
          curr++;
          amt += 100 * (i + 1);
          if (G <= amt) {
            ans = min(ans, curr);
            flag = true;
          }
        }
      }
    }
  }
  print(ans);
  return 0;
}
