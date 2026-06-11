#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int D = 10;

int d, g, p[D], c[D];

int main() {
  cin >> d >> g;
  rep(i, d) cin >> p[i] >> c[i];
  int ans = 1e4;
  rep(bit, 1<<d) {
    int slv = 0, pt = 0;
    rep(i, d) if (bit & 1<<i) {
      slv += p[i];
      pt += 100 * (1 + i) * p[i] + c[i];
    }
    if (pt >= g) {
      ans = min(ans, slv);
      continue;
    }
    int a = d - 1;
    while (bit & 1<<a) a--;
    if (pt + 100 * (1 + a) * (p[a] - 1) < g) continue;
    slv += (g - pt + 100 * (1 + a) - 1) / (100 * (1 + a));
    ans = min(ans, slv);
  }
  cout << ans << endl;
  return 0;
}