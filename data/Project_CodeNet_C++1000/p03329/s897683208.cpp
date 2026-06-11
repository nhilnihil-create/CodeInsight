#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int dp[200000];
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  int N;
  cin >> N;
  REP(i, N + 10) dp[i] = i;
  REP(i, N + 10) {
    for (int j = 1; longpow(6, j, MOD) <= N; j++) {
      chmin(dp[i + longpow(6, j, MOD)], dp[i] + 1);
    }
  }
  REP(i, N + 10) {
    for (int j = 1; longpow(9, j, MOD) <= N; j++) {
      chmin(dp[i + longpow(9, j, MOD)], dp[i] + 1);
    }
  }
  cout << dp[N] << endl;
}
