#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  ll N, M;
  scanf("%lld %lld", &N, &M);

  map<ll, ll> m;
  for (ll i = 0; i < N; i++) {
    ll k;
    scanf("%lld", &k);

    for (ll j = 0; j < k; j++) {
      ll f;
      scanf("%lld", &f);

      m[f] += 1;
    }
  }

  auto ite = m.begin();

  ll ans = 0;

  for (; ite != end(m); ite++) {
    if ((*ite).second == N) {
      ans++;
    }
  }
  cout << ans << endl;
}
