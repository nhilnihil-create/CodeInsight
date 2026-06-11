#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

struct Block {
  ll w, s, v;
  Block(ll w, ll s, ll v) : w(w), s(s), v(v) {}
};

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ll n;
  cin >> n;
  vector<Block> blocks;
  ll sMax = 0;
  REP(i, n) {
    ll w, s, v;
    cin >> w >> s >> v;
    blocks.push_back(Block(w, s, v));
    chmax(sMax, s);
  }
  sort(ALL(blocks),
       [](Block b1, Block b2) { return b2.s - b1.w > b1.s - b2.w; });

  vector<vector<ll>> dp(2, vector<ll>(sMax + 2, -1));
  dp[0][0] = 0;
  REP(i, n) REP(j, sMax + 2) {
    ll ci = i % 2, ni = !ci;
    if (dp[ci][j] == -1) {
      continue;
    }
    chmax(dp[ni][j], dp[ci][j]);
    if (j <= blocks[i].s) {
      chmax(dp[ni][min(j + blocks[i].w, sMax + 1)], dp[ci][j] + blocks[i].v);
    }
  }
  ll ans = 0;
  REP(j, sMax + 2) { ans = max(ans, dp[n % 2][j]); }
  cout << ans << endl;
}