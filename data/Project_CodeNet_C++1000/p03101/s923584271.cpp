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
  ll H, W;
  scanf("%lld %lld", &H, &W);

  ll h, w;
  scanf("%lld %lld", &h, &w);

  ll ans = H * W - H * w - h * W + w * h;

  cout << ans << endl;
}
