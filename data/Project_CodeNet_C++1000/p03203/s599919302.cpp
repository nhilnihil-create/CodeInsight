#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
#define fst first
#define snd second
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> inline int Log2(T& x) {int k; for(k=0; (T(1)<<k)<=x; ++k); return k;} // number of binary digits
template<typename T> inline int count_between(vector<T>& a, T l, T r) {
  return lower_bound(all(a), r) - lower_bound(all(a), l);
}


int main() {
  ll H, W, N; cin >> H >> W >> N;
  VV X(W);

  rep(i, N) {
    int x, y; cin >> x >> y;
    --x; --y;
    X[y].push_back(x);
  }
  rep(i, W) sort(all(X[i]));

  VV ava(W);
  rep(i, W) for (auto e : X[i]) {
    if (!ava[i].empty() && ava[i].back() == e) ava[i].pop_back();
    ava[i].push_back(e+1);
  }

  int now = 0;
  V top(W, INF);
  top[0] = 0;
  rep(i, W-1) {
    if (count_between(X[i], now+1, now+2) == 1) break;
    if (count_between(X[i+1], now+1, now+2) == 0) {
      ++now;
      top[i+1] = now;
      continue;
    }
    int can = *lower_bound(all(ava[i+1]), now+1);
    if (count_between(X[i], now, can) > 0) break;
    now = can;
    top[i+1] = can;
  }

  int ans = H;
  rep(i, W) {
    if (X[i].empty()) continue;
    if (lower_bound(all(X[i]), top[i]) == X[i].end()) continue;
    chmin(ans, *lower_bound(all(X[i]), top[i]));
  }
  cout << ans << endl;
  return 0;
}
