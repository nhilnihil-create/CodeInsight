#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  ll n;
  cin >> n;
  V<int> ms(1e6 + 1);

  ll ans = 0;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll m = n / i - 1;
      if (m == 0) continue;
      if (n / m == n % m) ans += m;
    }
  }
  cout << ans << endl;
}
