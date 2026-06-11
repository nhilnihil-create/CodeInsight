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
  VVll a(N, Vll(N));
  rep(i, N) rep(j, N) cin >> a[i][j];

  Vll dp(1<<N);

  rep(S, 1<<N) {
    rep(i, N) rep2(j, i+1, N) if ((S>>i&1) & (S>>j&1)) dp[S] += a[i][j];
    for (int T = S; T > 0; T = (T-1)&S) chmax(dp[S], dp[T] + dp[S-T]);
  }

  ll ans = dp[(1<<N)-1];
  cout << ans << endl;
  return 0;
}
