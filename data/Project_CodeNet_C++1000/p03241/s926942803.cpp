#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

set<ll> enum_divisor(ll m) {
  set<ll> divisors;
  for (ll i = 1; i*i <= m; ++i) {
    if (m % i != 0) continue;
    divisors.insert(i);
    if (i * i != m) divisors.insert(m / i);
  }
  return divisors;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  ll mx = m / n;
  set<ll> divisors = enum_divisor(m);
  for (auto itr = divisors.rbegin(); itr != divisors.rend(); itr++) {
    if (*itr <= mx) {
      cout << *itr << endl;
      break;
    }
  }

  return 0;
}
