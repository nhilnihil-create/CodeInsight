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

  ll x1, y1, x2, y2;
  scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

  ll wx = (x2 - x1);
  ll wy = (y2 - y1);

  ll x3 = x2 - wy;
  ll y3 = y2 + wx;
  ll x4 = x1 - wy;
  ll y4 = y1 + wx;

  cout << (x3) << " " << (y3) << " " << (x4) << " " << (y4) << endl;
}
