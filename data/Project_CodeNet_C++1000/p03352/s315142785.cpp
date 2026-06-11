#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  ll N;
  cin >> N;
  int mx = 1;
  for (int i = 2; i <= N; i++) {
    for (int j = 2; longpow(i, j, MOD) <= N; j++) {
      mx = max<ll>(mx, longpow(i, j, MOD));
    }
  }
  cout << mx << endl;
}