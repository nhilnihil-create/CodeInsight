#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll l = 2;
  ll r = 2;
  for (int i = n - 1; i >= 0; --i) {
    ll x = a[i];

    if (l % x != 0) {
      l += x - l % x;
    }

    if (r % x != 0) {
      r -= r % x;
    }

    if (l > r) {
      cout << -1 << endl;
      return 0;
    }

    r += x - 1;
  }

  cout << l << " " << r << endl;

  return 0;
}
