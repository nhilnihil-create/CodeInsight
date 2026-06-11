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
ll A[101010];
ll B[101010];
map<ll, ll> m;

int main() {
  cin >> N >> M;
  m[0]++;
  repe(i, 1, N) {
    cin >> A[i];
    B[i] = B[i - 1] + A[i];
    ll bm = B[i] % M;
    m[bm]++;
  }

  ll ans = 0;
  for (auto e : m) {
    ll n = e.second;
    if (n >= 2) {
      ans += n * (n - 1) / 2;
    }
  }
  cout << ans << endl;
}
