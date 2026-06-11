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
  ll H, W;
  scanf("%lld %lld", &H, &W);
  ll h, w;
  scanf("%lld %lld", &h, &w);

  cout << ((H - h) * (W - w)) << endl;
}
