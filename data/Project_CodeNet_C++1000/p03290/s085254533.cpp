#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int D, G;
  cin >> D >> G;
  vector<int> ps(D);
  vector<int> cs(D);
  rep(i, D) cin >> ps[i] >> cs[i];
  int ans = 1e9;
  for (int bit = 0; bit < (1 << D); bit++) {
    int s = 0, num = 0, m = -1;
    rep(i, D) {
      if (bit & (1 << i)) {
        s += 100 * (i + 1) * ps[i] + cs[i];
        num += ps[i];
      } else {
        m = i;
      }
    }
    if (s < G) {
      int s1 = 100 * (m + 1);
      int need = (G - s + s1 - 1) / s1;
      if (need >= ps[m]) {
        continue;
      }
      num += need;
    }
    ans = min(ans, num);
  }
  cout << ans << endl;

  return 0;
}