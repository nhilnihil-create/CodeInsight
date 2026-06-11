#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

// 12 -> 1,2,6,3,4
vector<ll> factor(ll n) {
  vector<ll> ret;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i != 1 && i * i != n) {
        ret.push_back(n / i);
      }
    }
  }
  return ret;
}

int main() {
  ll N;
  scanf("%lld", &N);

  ll ans = 0;

  for (ll i = 1; i <= N; i++) {
    if (i % 2 == 0) continue;
    if (factor(i).size() == 7) {
      ans++;
    }
  }
  cout << ans << endl;
}
