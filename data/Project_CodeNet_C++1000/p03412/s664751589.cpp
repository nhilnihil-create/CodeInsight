#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repi(i, a, b) for (int i = (a); i < int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())

using namespace std;
using i32 = int;
using i64 = long long;
using f64 = double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf64 = vector<f64>;
using vstr = vector<string>;

template<typename T, typename S> void amax(T &x, S y) { if (x < y) x = y; }
template<typename T, typename S> void amin(T &x, S y) { if (y < x) x = y; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  int n; cin >> n;
  vi32 a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  i32 ans = 0;
  rep(i, 30) {
    vi32 ma = a, mb = b;
    rep(j, n) ma[j] %= bit(i + 1);
    rep(j, n) mb[j] %= bit(i + 1);
    sort(all(mb));
    i32 cnt = 0;
    rep(j, n) {
      i32 c1 = lower_bound(all(mb), 2 * bit(i) - ma[j])
             - lower_bound(all(mb), 1 * bit(i) - ma[j]);
      i32 c2 = lower_bound(all(mb), 4 * bit(i) - ma[j])
             - lower_bound(all(mb), 3 * bit(i) - ma[j]);
      cnt += c1 + c2;
    }
    if (cnt % 2) ans += bit(i);
  }
  cout << ans << endl;
  return 0;
}
