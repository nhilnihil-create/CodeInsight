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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

vector<int> createEratos(int n)
{
  vector<int> isprime(n+1, 1);
  isprime[0] = 0;
  isprime[1] = 0;

  for (int i = 2; i * i <= n; i++) {
    if (isprime[i]) {
      int j = i + i;
      while (j <= n) {
        isprime[j] = 0;
        j = j + i;
      }
    }
  }
  return isprime;
}

// 階乗の素因数分解
vector<int> factfact(int n)
{
  vector<int> prime = createEratos(n);

  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      prime[i] = 0;
      for (int j = i; j <= n; j *= i) {
        prime[i] += n/j;
      }
    }
  }
  return prime;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n; cin >> n;
  auto factors = factfact(n);
  int o74 = 0;
  int o24 = 0;
  int o14 = 0;
  int o4 = 0;
  int o2 = 0;
  for (auto& v : factors) {
    if (v >= 74) o74++;
    if (v >= 24) o24++;
    if (v >= 14) o14++;
    if (v >= 4) o4++;
    if (v >= 2) o2++;
  }

  ll ans = 0;
  ans += o74;
  ans += o24 * (o2-1);
  ans += o14 * (o4-1);
  ans += (o4 * (o4-1) * (o2-2)) / 2;

  cout << ans << endl;

  return 0;
}
