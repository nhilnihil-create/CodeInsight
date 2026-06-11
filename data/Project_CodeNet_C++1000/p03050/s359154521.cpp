// 2020-09-06 22:22:41
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
namespace prime {
  bool is_prime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++) {
      if(n % i == 0) return false;
    }
    return true;
  }
  vector<ll> divisors(ll n) {
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++) {
      if(n % i == 0) {
        res.push_back(i);
        if(i != n / i) res.push_back(n / i);
      }
    }
    return res;
  }
  map<ll, int> prime_factors(ll n) {
    map<ll, int> res;
    if(n < 2) return res;
    for(ll i = 2; i * i <= n; i++) {
      while(n % i == 0) {
        res[i]++;
        n /= i;
      }
    }
    if(n > 1) res[n] = 1;
    return res;
  }
};

// clang-format on
void answer() {
  ll n;
  cin >> n;
  auto ds = prime::divisors(n);
  sort(ALL(ds));
  ll ans = 0;
  for (auto d : ds) {
    ll m = d - 1;
    if (m > 0 && n / m == n % m) ans += m;
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}