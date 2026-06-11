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

int main() {
  ll N, T;
  scanf("%lld %lld", &N, &T);

  vector<pair<ll, ll>> list;
  for (ll i = 0; i < N; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    list.emplace_back(make_pair(a, b));
  }

  sort(list.begin(), list.end());

  ll ans = -1;

  for (ll i = 0; i < list.size(); i++) {
    auto v = list[i];
    if (v.second <= T) {
      ans = (v.first);
      break;
    }
  }

  if (ans >= 0) {
    cout << ans << endl;
  } else {
    cout << "TLE" << endl;
  }
}
