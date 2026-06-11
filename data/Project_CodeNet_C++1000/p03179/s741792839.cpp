#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define REP(i, a) for (int i(0); i < (a); ++i)
#define FOR(i, a, b) for (int i(a); i <= (b); ++i)

#ifdef LOCAL
#define NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define F_1(F, ARG) F(ARG)
#define F_2(F, ARG, ...) F(ARG) F_1(F, __VA_ARGS__)
#define F_3(F, ARG, ...) F(ARG) F_2(F, __VA_ARGS__)
#define F_4(F, ARG, ...) F(ARG) F_3(F, __VA_ARGS__)
#define F_5(F, ARG, ...) F(ARG) F_4(F, __VA_ARGS__)
#define F_6(F, ARG, ...) F(ARG) F_5(F, __VA_ARGS__)
#define FOR_EACH(F, ...)                                                       \
  NTH_ARG(__VA_ARGS__, F_6, F_5, F_4, F_3, F_2, F_1)(F, __VA_ARGS__)

#define C_RED "\033[2;31m"
#define C_BLUE "\033[1;34m"
#define C_GREEN "\033[1;32m"
#define C_RESET "\033[0m"

#define watch(x) cerr << C_GREEN #x " = " C_BLUE << (x) << C_RESET "; ";
#define debug(...)                                                             \
  cerr << C_RED "Line " << __LINE__ << ": " C_RESET;                           \
  FOR_EACH(watch, __VA_ARGS__)                                                 \
  cerr << endl
#else
#define debug(...)
#endif

using namespace std;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decltype(begin(declval<T>())),
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
  os << '[';
  for (auto it = begin(c); it != end(c); ++it)
    os << (it == begin(c) ? "" : ", ") << *it;
  return os << ']';
}
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  const int MOD = 1e9 + 7;

  auto addOp = [&](int a, int b) { return (a + b) % MOD; };

  vector<int> pref(n + 1);
  pref[1] = 1;

  for (int len = 2; len <= n; ++len) {
    partial_sum(ALL(pref), pref.begin(), addOp);
    vector<int> nxt(n + 1);
    for (int last = 1; last <= len; ++last) {
      int l, r;
      if (s[len - 2] == '<') {
        l = 1;
        r = last - 1;
      } else {
        l = last;
        r = len - 1;
      }
      nxt[last] = (pref[r] - pref[l - 1] + MOD) % MOD;
    }
    pref.swap(nxt);
  }
  ll ans = accumulate(ALL(pref), 0, addOp);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
