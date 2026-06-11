// 2020-09-28 19:19:45
// clang-format off
#include <bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
// #include <atcoder/convolution>
// #include <atcoder/dsu>
// #include <atcoder/fenwicktree>
// #include <atcoder/lazysegtree>
// #include <atcoder/math>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/modint>
// #include <atcoder/scc>
// #include <atcoder/segtree>
// #include <atcoder/string>
// #include <atcoder/twosat>
// #include <atcoder/all>
// using namespace atcoder;

// clang-format on
void answer() {
  string s;
  cin >> s;
  int n = s.size();
  if (n <= 3) {
    if (n == 2 && s == "10") {
      cout << "1 2" << '\n';
    } else if (n == 3 && s == "110") {
      cout << "1 2" << '\n';
      cout << "2 3" << '\n';
    } else {
      cout << "-1" << '\n';
    }
    return;
  }
  vector<int> a(n + 1);
  rep(i, n) a[i + 1] = s[i] - '0';
  if (a[1] == 0 || a[n - 1] == 0 || a[n] == 1) {
    cout << "-1" << '\n';
    return;
  }
  REPC(i, 1, n / 2) if (a[i] != a[n - i]) {
    cout << -1 << '\n';
    return;
  }
  vector<int> p(n + 1, 0);
  int ci = 1, ni = 2;
  while (ni <= n / 2 + 1) {
    if (a[ni - 1]) {
      p[ci] = ni;
      ci = ni;
    } else {
      p[ni] = ci;
    }
    ni++;
  }
  while (ni <= n) p[ni++] = ci;
  REPC(i, 1, n) if (p[i] > 0) cout << i << ' ' << p[i] << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}