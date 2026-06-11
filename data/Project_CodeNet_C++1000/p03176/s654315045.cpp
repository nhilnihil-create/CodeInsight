#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007)
#define IINF (1<<28)
#define LINF (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"

struct SegmentTree {
  long long n;
  std::vector<long long> node;

  void init(long long _n) {
    n = 1;
    while(n < _n) n *= 2;
    node.resize(2*n-1, 0);
  }

  void update(long long i, long long v) {
    long long k = i+n-1;
    node[k] = v;
    while(k > 0) {
      k = (k-1)/2;
      node[k] = std::max(node[2*k+1], node[2*k+2]);
    }
  }

  long long find(long long s, long long t) {
    return _find(s, t, 0, 0, n);
  }

  long long _find(long long s, long long t, long long k, long long l, long long r) {
    if(r <= s || t <= l) return 0;
    if(s <= l && r <= t) return node[k];
    long long m = (r+l)/2, kl = 2*k+1, kr = 2*k+2;
    return std::max(_find(s, t, kl, l, m), _find(s, t, kr, m, r));
  }
};

namespace solver {
  using namespace std;
  typedef long long ll;

  static const int MAX = 200020;
  int N, hs[MAX], as[MAX];
  ll dp[MAX];
  SegmentTree st;

  void init() {
    cin >> N;
    rep(i, N) {
      cin >> hs[i];
      hs[i]--;
    }
    rep(i, N) {
      cin >> as[i];
    }
  }

  void solve() {
    st.init(N);
    ll maxv = 0;
    rep(i, N) {
      dp[hs[i]] = st.find(0, hs[i]) + as[i];
      st.update(hs[i], dp[hs[i]]);
      maxv = max(maxv, dp[hs[i]]);
    }
    cout << maxv << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}