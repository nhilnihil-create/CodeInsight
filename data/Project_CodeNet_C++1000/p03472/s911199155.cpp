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
ll N, H;
ll a[101010], b[101010];
ll maxa;
ll csumb[101010];

int main() {
  cin >> N >> H;
  rep(i, 0, N) {
    cin >> a[i] >> b[i];
    chmax(maxa, a[i]);
  }

  sort(b, b + N, greater<ll>());

  rep(i, 0, N) { csumb[i + 1] = csumb[i] + b[i]; }

  ll ans = INF;
  repe(i, 0, N) {
    ll cnt = i;
    ll damage = csumb[i];
    if (H - damage > 0) {
      ll rest = H - damage;
      cnt += ((rest + maxa - 1) / maxa);
    }
    chmin(ans, cnt);
  }

  cout << ans << endl;
}