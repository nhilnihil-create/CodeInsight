#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<ll> s(n + 1);
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    s[i + 1] = s[i] + a;
  }

  vector<ll> x;
  for (int l = 1; l <= n; ++l) for (int r = l; r <= n; ++r) {
    x.push_back(s[r] - s[l - 1]);
  }

  ll result = 0;
  for (ll b = 40; b >= 0; --b) {
    ll cur = 1LL << b;
    vector<ll> y;
    for (ll t : x) if (t & cur) y.push_back(t);
    if (y.size() >= k) {
      result |= cur;
      x = y;
    }
  }

  cout << result << endl;

  return 0;
}
