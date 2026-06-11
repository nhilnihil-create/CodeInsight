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
long long gcd(long long a, long long b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int N, M;
string S, T;

int main() {
  cin >> N >> M;
  cin >> S >> T;

  ll L = lcm(N, M);
  ll g = gcd(N, M);

  ll ng = N / g;
  ll mg = M / g;

  for (int i = 0; i < g; ++i) {
    if (S[ng * i] != T[mg * i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << L << endl;
}
