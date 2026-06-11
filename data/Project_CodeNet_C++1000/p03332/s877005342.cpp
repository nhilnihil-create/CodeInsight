#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  auto pow = [&](long long x, int p) {
    x %= MOD;
    long long y = 1;
    while (p) {
      if (p & 1) {
        y = x * y % MOD;
      }
      x = x * x % MOD;
      p >>= 1;
    }
    return y;
  };
  vector<long long> fact(n + 1), facti(n + 1);
  fact[0] = 1, facti[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    facti[i] = pow(fact[i], MOD - 2);
  }
  long long ans = 0;
  for (long long x = 0; x <= n; ++x) {
    long long y = (k - a * x) / b;
    if ((k - a * x) % b == 0 && n >= y && y >= 0) {
      long long sub = fact[n];
      sub = sub * fact[n] % MOD;
      sub = sub * facti[x] % MOD;
      sub = sub * facti[y] % MOD;
      sub = sub * facti[n - x] % MOD;
      sub = sub * facti[n - y] % MOD;
      ans = (ans + sub) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
