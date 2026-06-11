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

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) {
    res[n]++;
  }
  return res;
}

ll N;

int main() {
  cin >> N;
  map<ll, ll> pf;
  repe(i, 2, N) {
    auto mp = prime_factor(i);
    for (auto e : mp) {
      pf[e.first] += e.second;
    }
  }

  ll over2 = 0, over4 = 0, over14 = 0, over24 = 0, over74 = 0;
  for (auto e : pf) {
    if (e.second >= 74) ++over74;
    if (e.second >= 24) ++over24;
    if (e.second >= 14) ++over14;
    if (e.second >= 4) ++over4;
    if (e.second >= 2) ++over2;
  }

  ll ans = over4 * (over4 - 1) / 2 * (over2 - 2);
  ans += over24 * (over2 - 1);
  ans += over74;
  ans += over14 * (over4 - 1);
  cout << ans << endl;
}
