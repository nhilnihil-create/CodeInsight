#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
ll N, M;
ll x[1010], y[1010], z[1010];
ll total[1010];

int main() {
  cin >> N >> M;
  rep(i, 0, N) { cin >> x[i] >> y[i] >> z[i]; }
  ll ans = 0;
  for (int bit = 0; bit < (1 << 3); ++bit) {
    rep(i, 0, N) {
      ll xx = x[i];
      ll yy = y[i];
      ll zz = z[i];
      if (bit & 1) {
        xx = -xx;
      }
      if (bit & (1 << 1)) {
        yy = -yy;
      }
      if (bit & (1 << 2)) {
        zz = -zz;
      }
      total[i] = xx + yy + zz;
    }

    sort(total, total + N, greater<ll>());
    ll sum = 0;
    rep(i, 0, M) { sum += total[i]; }
    chmax(ans, sum);
  }
  cout << ans << endl;
}
