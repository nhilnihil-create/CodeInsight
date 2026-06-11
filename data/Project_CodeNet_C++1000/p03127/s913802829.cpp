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

const double pi = 3.141592653589793;
// -------------------------------------------------------
ll gcd(ll a, ll b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

ll N;
ll A[101010];

int main() {
  cin >> N;
  rep(i, 0, N) { cin >> A[i]; }
  ll ans = gcd(A[0], A[1]);
  rep(i, 2, N) { ans = gcd(ans, A[i]); }
  cout << ans << endl;
}
