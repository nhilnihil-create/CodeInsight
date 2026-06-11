#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())

using namespace std;

using i64 = long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

void yes() { cout << "Yes" << endl; exit(0); }
void no() { cout << "No" << endl; exit(0); }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> void amax(T &x, T y) { x = max(x, y); }
template <typename T> void amin(T &x, T y) { x = min(x, y); }
template <typename T> T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

const int INF = 1001001001;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void solve() {
  int n;
  cin >> n;
  vi32 w(n), s(n), v(n);
  rep(i, n) {
    cin >> w[i] >> s[i] >> v[i];
  }
  vi32 o(n);
  iota(all(o), 0);
  sort(all(o), [&](int i, int j) {
    return s[i] + w[i] < s[j] + w[j];
  });
  vector<vi64> dp(n + 1, vi64(10002, -1));
  dp[0][0] = 0;
  rep(i, n) repc(j, 10001) {
    if (dp[i][j] == -1) continue;
    int x = o[i];
    amax(dp[i + 1][j], dp[i][j]);
    if (j <= s[x]) {
      int weight = j + w[x];
      if (weight > 10000) weight = 10001;
      amax(dp[i + 1][weight], dp[i][j] + v[x]);
    }
  }
  i64 ans = 0;
  repc(j, 10001) amax(ans, dp[n][j]);
  cout << ans << endl;
}
