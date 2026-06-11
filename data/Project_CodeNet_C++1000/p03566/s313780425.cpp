#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, x, n) for (int i = (x); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
template<typename T> void cmax(T &a, T b) { a = max(a, b); }
template<typename T> void cmin(T &a, T b) { a = min(a, b); }

signed main() {
  int n;
  cin >> n;
  vector<double> t(n), v(n);
  rep(i, n) cin >> t[i];
  rep(i, n) cin >> v[i];
  int tm = accumulate(all(t), 0LL);
  vector<double> sp(2 * tm + 1, INF);
  int now = 0;
  rep(i, n) {
    rep(j, t[i]) {
      int t = now + j * 2;
      int tt = now + j * 2 + 1;
      cmin(sp[t], v[i]);
      cmin(sp[tt], v[i]);
    }
    now += t[i] * 2;
    cmin(sp[now], v[i]);
  }
  sp[0] = sp[2 * tm] = 0;
  for (int i = 0; i < 2 * tm + 1; i++) cmin(sp[i + 1], sp[i] + 0.5);
  for (int i = 2 * tm; i >= 0; i--) cmin(sp[i], sp[i + 1] + 0.5);

  double ans = 0;
  rep(i, 2 * tm + 1) ans += (sp[i] + sp[i + 1]) * 0.5 / 2;

  printf("%lf\n", ans);
  return 0;
}
