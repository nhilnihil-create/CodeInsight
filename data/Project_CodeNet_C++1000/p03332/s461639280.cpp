#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
constexpr ll MOD = 998244353;

class Enumeration {
public:
  explicit Enumeration(int n, uint64_t mod)
    : mod(mod), fact(n), inv(n), finv(n) {
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
private:
  uint64_t mod;
  vector<uint64_t> fact, inv, finv;
};

int main() {
  ll n, a, b, k;
  cin >> n >> a >> b >> k;

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
