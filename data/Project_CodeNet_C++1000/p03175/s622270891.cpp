// 22
#include <bits/stdc++.h>
using namespace std;
#define coutc "\033[48;5;196m\033[38;5;15m"
#define endc "\033[0m"
#define endl '\n'
#define M(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) M(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep4(_, x, n, s) for (int _ = x; (s < 0) ? _ > n : _ < n; _ += s)
#define rep3(_, x, n) rep4(_, x, n, (x < n ? 1 : -1))
#define rep2(_, n) rep3(_, 0, n)
#define rep1(n) rep2(i, n)
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
  rep(i, len(v)) o << setw(7) << left << v[i];
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
#ifdef DEBUG
  cerr << coutc << e;
  ((cerr << " " << r), ..., (cerr << endc << endl));
#endif
}

// Notes: https://searleser97.gitlab.io/competitive-programming-notes/AtCoder/dp_p.png

void _main(int tc) {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  auto addEdge = [&](int u, int v) { adj[u].pb(v); };
  rep(n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    addEdge(u, v);
    addEdge(v, u);
  }
  const int mod = 1e9 + 7;
  function<pairii(int, int)> f = [&](int u, int p) -> pairii {
    int ifwhitecnt = 1, ifblackcnt = 1;
    for (int v : adj[u]) {
      if (v == p) continue;
      auto ans = f(v, u);
      ifwhitecnt = ((li)ifwhitecnt * ((ans.fi + ans.se) % mod)) % mod;
      ifblackcnt = ((li)ifblackcnt * ans.fi) % mod;
    }
    return {ifwhitecnt, ifblackcnt};
  };
  auto ans = f(0, 0);
  cout << ((ans.fi + ans.se) % mod) << endl;
}
// 7
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0), exit(0);
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}