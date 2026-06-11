#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())

using namespace std;

using i64 = long long;
using f80 = long double;
using vi32 = vector<i64>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template <typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline T power(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
template <typename T, typename S> istream& operator>>(istream &is, pair<T, S> &p) { is >> p.first >> p.second; return is; }
template <typename T, typename S> ostream& operator<<(ostream &os, pair<T, S> &p) { cout << p.first << ' ' << p.second; return os; }

#define int i64
#define endl '\n'

void solve() {
  int n; cin >> n;
  vi32 a(n); cin >> a;
  
  vi32 sums(n + 1);
  partial_sum(all(a), sums.begin() + 1);
  
  auto inc = [&](int i) { return (i + 1) % n; };
  auto dec = [&](int i) { return (i + n - 1) % n; };

  auto sum = [&](int l, int r) {
    if (l <= r) return sums[r] - sums[l];
    return sums[n] - sums[l] + sums[r];
  };

  auto diff = [&](int l, int m, int r) {
    if (l == m || m == r) return (int) 1e18;
    return abs(sum(l, m) - sum(m, r));
  };

  int ans = 1e18;

  rep(i, 1) {
    int l = inc(i);
    int j = inc(l);
    int r = inc(j);

    for (int e = dec(i); j != e; j = inc(j)) {
      while (diff(i, l, j) > diff(i, l + 1, j)) l = inc(l);
      while (diff(j, r, i) > diff(j, r + 1, i)) r = inc(r);

      auto mm = minmax({
        sum(i, l), sum(l, j), sum(j, r), sum(r, i)
      });
      amin(ans, mm.second - mm.first);
    }
  }

  cout << ans << endl;
}
