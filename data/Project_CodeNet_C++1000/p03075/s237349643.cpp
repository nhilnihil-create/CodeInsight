#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll a, b, c, d, e;
  scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);

  ll k;
  scanf("%lld", &k);

  cout << ((e - a) <= k ? "Yay!" : ":(") << endl;
}
