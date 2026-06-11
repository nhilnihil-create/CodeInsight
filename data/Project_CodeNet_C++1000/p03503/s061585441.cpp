#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll n;
  cin >> n;

  vector<vector<ll>> f(n ,vector<ll>(10));
  vector<vector<ll>> p(n, vector<ll>(11));
  ll ans = -INF;

  rep(i, n) {
    rep(j, 10) cin >> f[i][j];
  }
  rep(i, n) {
    rep(j, 11) cin >> p[i][j];
  }

  rep(bit, 1<<10) {
    vector<int> d(10);
    rep(i, 10) if (bit & (1 << i)) {
      d[i] = 1;
    }

    if (__builtin_popcount(bit) == 0) continue;

    ll sum = 0;
    rep(i, n) {
      ll cnt = 0;
      rep(j, 10) {
        if (d[j] == f[i][j] && d[j] == 1) cnt++;
      }
      sum += p[i][cnt];
    }

    chmax(ans, sum);
  }

  cout << ans << endl;

  return 0;
}
