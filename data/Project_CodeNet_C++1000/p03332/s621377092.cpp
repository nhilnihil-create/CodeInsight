#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
constexpr ll MOD = 998244353;

class Enumeration {
public:
  explicit Enumeration(int n, uint64_t mod)
    : fact(n), inv(n), finv(n), mod(mod) {
    fact[0] = finv[0] = inv[1] = 1;
    for (int i = 2; i < n; ++i) inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    for (int i = 1; i < n; ++i) {
      fact[i] = fact[i - 1] * i % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
  }
  uint64_t operator()(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;
    return fact[n] * finv[n - k] % mod * finv[k] % mod;
  }
  uint64_t modpow(uint64_t x, uint64_t e) {
    uint64_t res = 1;
    while (e > 0) {
      if (e & 1) res = res * x % mod;
      x = x * x % mod;
      e >>= 1;
    }
    return res;
  }

private:
  uint64_t mod;
  vector<uint64_t> fact, inv, finv;
};

int main() {
  ll n, a, b, k;
  cin >> n >> a >> b >> k;

  // 赤、緑、青いずれか2つが求まれば場合の数の計算。
  // でもO(n ^ 2)はむり。。。
  // 特典が2種類なのでこれを固定しよう

  Enumeration e(n + 1, MOD);
  ll ans = 0;
  for (ll anum = 0; anum <= n; ++anum) {
    if (k < a * anum) break;
    ll rem = k - a * anum;
    if (rem % b != 0) continue;
    ll bnum = rem / b;
    ans = (ans + e(n, anum) * e(n, bnum) % MOD) % MOD;
  }
  cout << ans << endl;
  return 0;
}