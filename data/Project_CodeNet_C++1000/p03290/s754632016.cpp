#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main() {
  int d, g;
  cin >> d >> g;
  vector<int> p(d, 0), c(d, 0);
  rep(i, d) cin >> p[i] >> c[i];

  ll ans = INF;
  rep(bit, 1 << d) {
    ll tot = 0;
    ll num = 0;

    // 全完する難易度帯を 2D 通りで決め打ちする
    rep(i, d) {
      if (bit >> i & 1) {
        tot += 100 * (i + 1) * p[i] + c[i];
        num += p[i];
      }
    }

    if (tot >= g) {
      // 決め打ちで g 点に到達している場合はそれで OK
      ans = min(ans, num);
    } else {
      // それだけでは到達していない場合, 全完対象でないもののうち
      // Greedy に高難易度順から解いていけば OK
      for (int i = d - 1; i >= 0; i--) {
        if (bit >> i & 1) continue;
        rep(j, p[i]) {
          if (tot >= g) break;
          tot += 100 * (i + 1);
          num++;
        }
      }
      ans = min(ans, num);
    }
  }

  cout << ans << endl;

  return 0;
}
