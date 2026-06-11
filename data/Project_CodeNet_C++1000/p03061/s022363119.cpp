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

ll N;
ll A[101010];

long long gcd(long long a, long long b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

ll cgcd[101010], rcgcd[101010];

int main() {
  cin >> N;
  rep(i, 0, N) { cin >> A[i]; }
  cgcd[0] = A[0];
  rep(i, 1, N) { cgcd[i] = gcd(cgcd[i - 1], A[i]); }
  rcgcd[N - 1] = A[N - 1];
  for (int i = N - 2; i >= 0; --i) {
    rcgcd[i] = gcd(rcgcd[i + 1], A[i]);
  }

  ll ans = max(cgcd[N - 2], rcgcd[1]);
  for (int i = 1; i < N - 1; ++i) {
    chmax(ans, gcd(cgcd[i - 1], rcgcd[i + 1]));
  }
  cout << ans << endl;
}
