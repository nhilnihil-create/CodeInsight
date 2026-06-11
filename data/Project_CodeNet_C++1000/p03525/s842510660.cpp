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
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))

using namespace std;

using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); return a / gcd(a, b) * b; }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template <typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

void solve() {
  int n;
  cin >> n;
  vi32 cnt(13);
  cnt[0] = 1;
  rep(i, n) {
    int d;
    cin >> d;
    cnt[d]++;
  }
  if (cnt[0] >= 2) {
    cout << 0 << endl;
    return;
  }
  reps(i, 12) {
    if (cnt[i] >= 3) {
      cout << 0 << endl;
      return;
    }
  }
  vi32 lst;
  repc(i, 12) {
    rep(j, cnt[i]) lst.push_back(i);
  }
  int l = lst.size();
  int ans = 0;
  rep(i, bit32(l)) {
    bitset<25> c;
    c[24] = 1;
    bool ok = true;
    rep(j, l) {
      int d;
      if (i & bit32(j)) {
        d = (24 - lst[j]) % 24;
      } else {
        d = lst[j];
      }
      if (c[d]) ok = false;
      else c[d] = 1;
    }
    if (!ok) continue;

    int mi = 1e9;
    int cn = 1;
    vi32 ls;
    reps(j, 25) {
      if (!c[j]) {
        cn++;
      } else {
        amin(mi, cn);
        cn = 1;
      }
    }
    amax(ans, mi);
  }
  cout << ans << endl;
}
