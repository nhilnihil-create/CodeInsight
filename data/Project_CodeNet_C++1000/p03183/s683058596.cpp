#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using VVVll = vector<VVll>;
using VVVld = vector<VVld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}


int main() {
  int N; cin >> N;
  VVll a(N, Vll(3));
  rep(i, N) cin >> a[i][0] >> a[i][1] >> a[i][2];
  sort(all(a), [] (Vll x, Vll y) { return x[0]+x[1] > y[0]+y[1]; });

  const int S = 1e4;
  VVll dp(N+1, Vll(S+2));

  rep(i, N) rep(w, S+1) {
    int wi = a[i][0];
    int si = a[i][1];
    ll vi = a[i][2];
    dp[i+1][w] = dp[i][w];
    if (w <= si) chmax(dp[i+1][w], vi + dp[i][min(w+wi, S+1)]);
  }

  ll ans = dp[N][0];
  cout << ans << endl;
  return 0;
}
