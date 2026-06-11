#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  ll l = lcm(n, m);
  bool ok = true;
  rep(i, 0, gcd(n, m)) ok &= s[(l / m * i) % n] == t[(l / n * i) % m];
  cout << (ok ? l : -1) << '\n';
  return 0;
}