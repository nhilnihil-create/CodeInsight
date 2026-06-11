#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  vector<ll> list;
  for (ll i = 0; i < 3; i++) {
    ll v;
    scanf("%lld", &v);
    list.emplace_back(v);
  }
  sort(list.begin(), list.end());

  ll ans = list[2] * 10 + list[1] + list[0];
  cout << ans << endl;
}
