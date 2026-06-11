#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  ll n; cin >> n;
  struct Block {
    ll w, s, v;
    Block(ll w_, ll s_, ll v_) : w(w_), s(s_), v(v_) {}
    bool operator<(const Block& rhs) const {
      return w + s < rhs.w + rhs.s;
    }
  };
  vector<Block> blocks;
  rep(i, n) {
    ll w, s, v; cin >> w >> s >> v;
    blocks.emplace_back(Block(w, s, v));
  }
  sort(ALL(blocks));
  vector<ll> dp(20020, 0), p(20020, 0);
  rep(i,n) {
    swap(p, dp);
    rep(j, 20010) {
      const Block& b = blocks[i];
      dp[j] = p[j];
      if(b.w <= j && b.s >= j-b.w) chmax(dp[j], p[j-b.w] + b.v);
    }
  }
  ll ans = 0;
  rep(j, 20010) chmax(ans, dp[j]);
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}