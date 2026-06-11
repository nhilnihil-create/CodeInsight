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

// Notes: https://searleser97.gitlab.io/competitive-programming-notes/AtCoder/dp_o.png

void _main(int tc) {
  int n;
  cin >> n;
  vector<vector<int>> can(n, vector<int>(n));
  rep(n) { rep(j, n) cin >> can[i][j]; }
  int const mod = 1e9 + 7;
  auto addSelf = [](int &a, int b) -> void {
    a += b;
    if (a >= mod) a -= mod;
  };

  /************* Recursive ************* O(N*2^21) fast enough
  vector<vector<int>> mem(n, vector<int>(1 << n, -1));
  function<int(int, int)> f = [&](int i, int mask) -> int {
    if (mask == (1 << n) - 1) return 1;
    if (i == n) return 0;
    if (mem[i][mask] != -1) return mem[i][mask];
    mem[i][mask] = 0;
    rep(j, n) {
      if (can[i][j] && ((mask >> j) & 1) == 0)
        addSelf(mem[i][mask], f(i + 1, mask | (1 << j)));
    }
    return mem[i][mask];
  };
  cout << f(0, 0) << endl;
  *********** End Recursive ***********/

  /*
    Notice that in the previous function we are just going through 2^n states
    and not "n*2^n". Because we can observe that the index "i" always
    corresponds exactly to the number of "1" bits in mask, because if there are
    "i" women selected that means that there will be "i" bits set to "1" and it
    also means that the first "i" men are also already selected. Therefore index
    "i" is equal to the number of "1" bits in mask.
  */

  /************* Recursive ************* O(N*2^21) optimized
  vector<int> mem(1 << n, -1);
  function<int(int)> f = [&](int mask) -> int {
    if (mask == (1 << n) - 1) return 1;
    int i = __builtin_popcount(mask);
    if (i == n) return 0;
    if (mem[mask] != -1) return mem[mask];
    mem[mask] = 0;
    rep(j, n) {
      if (can[i][j] && ((mask >> j) & 1) == 0)
        addSelf(mem[mask], f(mask | (1 << j)));
    }
    return mem[mask];
  };
  cout << f(0) << endl;
  *********** End Recursive ***********/

  vector<int> mem(1 << n);

  mem[(1 << n) - 1] = 1;

  rep(mask, (1 << n) - 2, -1) {
    int i = __builtin_popcount(mask);
    rep(j, n) {
      if (can[i][j] && ((mask >> j) & 1) == 0) {
        addSelf(mem[mask], mem[mask | (1 << j)]);
      }
    }
  }
  cout << mem[0] << endl;
}
// 7
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  _main(0), exit(0);
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
}