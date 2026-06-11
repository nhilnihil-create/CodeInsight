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
  // std::cout << std::fixed << std::setprecision(10);

  ll v;
  scanf("%lld", &v);

  map<ll, ll> m;
  ll i = 1;
  for (;; i++) {
    if (m[v]) {
      break;
    }
    m[v] = 1;

    // cout << v << endl;
    if (v % 2 == 0) {
      v = v / 2;
    } else {
      v = v * 3 + 1;
    }
  }
  cout << (i) << endl;
}

// 1,000,000