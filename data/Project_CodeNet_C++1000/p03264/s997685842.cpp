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

  ll K;
  scanf("%lld", &K);

  ll odd = 1 + (K - 1) / 2;
  ll even = K / 2;

  ll ans = odd * even;

  cout << ans << endl;
}
