// 21
#include <bits/stdc++.h>
using namespace std;
#define coutc "\033[48;5;196m\033[38;5;15m"
#define endc "\033[0m"
#define endl '\n'
#define M(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) M(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep4(_, x, n, s) for (int _ = x; (s < 0) ? _ > n : _ < n; _ += s)
#define rep3(_, x, n) rep4(_, x, n, (x < n ? 1 : -1))
#define rep2(_, n) rep3(_, 0, n)
#define fi first
#define se second
#define pb push_back
#define pairii pair<int, int>
#define all(x) x.begin(), x.end()
#define len(x) int(x.size())
#define lli __int128_t
#define li long long int
#define ld long double
// 4
template <class A, class B>
ostream &operator<<(ostream &o, const pair<A, B> &p) {
  return o << "(" << p.fi << ", " << p.se << ")";
}
// 5
template <class T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  rep(i, len(v)) o << setw(7) << v[i];
  return o << endc << endl << coutc;
}
// 5
template <class A, class B>
ostream &operator<<(ostream &o, const map<A, B> &m) {
  for (auto &kv : m) o << kv;
  return o;
}
// 7
template <class T, class... Ts>
void debug(const T &e, const Ts &... r) {
#ifdef LOCAL
  cerr << coutc << e;
  ((cerr << " " << r), ..., (cerr << endc << endl));
#endif
}

// Notes: https://searleser97.gitlab.io/competitive-programming-notes/AtCoder/dp_n.png

void _main(int tc) {
  int n;
  cin >> n;
  vector<li> v(n);
  rep(i, n) cin >> v[i];
  const li inf = 2e18;
  vector<li> pref = v;
  rep(i, 1, n) pref[i] += pref[i - 1];
  /************* Recursive *************
  vector<vector<li>> mem(n, vector<li>(n, inf));
  function<li(int, int)> f = [&](int L, int R) -> li {
    if (L == R) return 0;
    if (mem[L][R] != inf) return mem[L][R];
    li sum = pref[R] - (L == 0 ? 0 : pref[L - 1]);
    rep(pivot, L, R) {
      mem[L][R] = min(mem[L][R], f(L, pivot) + f(pivot + 1, R) + sum);
    }
    return mem[L][R];
  };
  cout << f(0, n - 1) << endl;
  *********** End Recursive ***********/
  vector<vector<li>> mem(n, vector<li>(n, inf));
  rep(R, n) {
    rep(L, R, -1) {
      if (L == R) {
        mem[L][R] = 0;
        continue;
      }
      li sum = pref[R] - (L == 0 ? 0 : pref[L - 1]);
      rep(pivot, L, R) {
        mem[L][R] = min(mem[L][R], mem[L][pivot] + mem[pivot + 1][R] + sum);
      }
    }
  }
  cout << mem[0][n - 1] << endl;
}
// 7
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0), exit(0);
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}