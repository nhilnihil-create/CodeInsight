#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repi(i, a, b) for (int i = (a); i < int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))

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

i32 n;
vi64 a, S;

i32 idx(i32 a, i32 b) {
  i32 l = a, r = b;
  while (true) {
    i32 m = (l + r) / 2;
    i64 x = abs((S[b] - S[m - 1]) - (S[m - 1] - S[a]));
    i64 y = abs((S[b] - S[m]) - (S[m] - S[a]));
    i64 z = abs((S[b] - S[m + 1]) - (S[m + 1] - S[a]));
    if (x >= y && y <= z) return m;
    if (x <= y) r = m;
    else l = m;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  cin >> n;
  a = vi64(n); rep(i, n) cin >> a[i];
  S = vi64(n + 1);
  partial_sum(all(a), S.begin() + 1);
  i64 ans = 1e18;
  repi(k, 2, n - 1) {
    i32 a = idx(0, k);
    i32 b = idx(k, n);
    vi64 v = {S[a], S[k]-S[a], S[b]-S[k], S[n]-S[b]};
    sort(all(v));
    amin(ans, v[3]-v[0]);
  }
  cout << ans << endl;
  return 0;
}
