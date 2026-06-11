#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    a[i] = x;
  }

  unordered_multiset<ll> s(a.begin(), a.end());
  sort(a.rbegin(), a.rend());

  int result = 0;
  for (int x : a) {
    auto it = s.find(x);
    if (it == s.end()) continue;
    s.erase(it);

    for (ll d = 1; d <= 2 * x; d *= 2) {
      if (d < x) continue;
      ll r = d - x;
      auto it = s.find(r);
      if (it == s.end()) {
        continue;
      }
      s.erase(it);
      result++;
      break;
    }
  }

  cout << result << endl;

  return 0;
}
