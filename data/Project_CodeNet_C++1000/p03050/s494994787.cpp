#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
int main() {
  ll n;
  cin >> n;
  multiset<ll> factors;
  for (ll i = 1; i <= sqrt(n); i++) {
    if (n % i == 0)
      factors.insert(i), factors.insert(n / i);
  }
  ll ans = 0;
  for (ll x : factors) {
    ll m = n / x - 1;
    // cout << m << ' ' << endl;
    if (m != 0 && n % m != n / m)
      continue;
    ans += m;
  }
  cout << ans << endl;
}