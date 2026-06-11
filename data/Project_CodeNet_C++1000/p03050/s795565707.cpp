#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define rrep(i, a, b) for (int i = int(a) - 1; i >= b; i--)
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<ll> yakusu;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      yakusu.emplace_back(i);
      yakusu.emplace_back(n / i);
    }
  }

  ll ans = 0;
  // amari = k torusuto
  // N = (m+1)*k toarawaseru
  rep(i, 0, sz(yakusu)) {
    if (yakusu[i] == 1)
      continue;
    if (n % (yakusu[i] - 1) == n / (yakusu[i] - 1)) {
      ans += yakusu[i] - 1;
    }
  }

  cout << ans << endl;
}