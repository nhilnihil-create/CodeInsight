#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll Pow(ll x, ll n) {
  ll result = 1;
  while (n > 0) {
    if (n % 2) {
      n--;
      result *= x;
      result %= mod;
    } else {
      n /= 2;
      x *= x;
      x %= mod;
    }
  }
  return result;
}

ll Inv(ll x) {
  return Pow(x, mod - 2);
}

const int maxn = 3 * 100 * 1000 + 2;
ll fact[maxn];

ll C(int n, int k) {
  ll result = fact[n];
  result = result * Inv(fact[k]) % mod;
  result = result * Inv(fact[n - k]) % mod;
  return result;
}

int main()
{
  ll n, A, B, k;
  cin >> n >> A >> B >> k;

  fact[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fact[i] = fact[i - 1] * i % mod;
  }

  ll result = 0;
  for (ll x = 0; x <= n; ++x) {
    if (k - x * A < 0) continue;
    if ((k - x * A) % B != 0) continue;
    ll y = (k - x * A) / B;
    if (y > n) continue;

    result += C(n, x) * C(n, y);
    result %= mod;
  }
  cout << result << endl;

  return 0;
}
