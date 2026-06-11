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
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) a[i + 1] += a[i];

  ll result = a.back();

  int l = 0;
  int r = 0;
  for (int m = 1; m < n; ++m) {
    while (l + 1 < m) {
      cerr << l << endl;
      ll curValue = abs(2 * a[l] - a[m]);
      ll nextValue = abs(2 * a[l + 1] - a[m]);
      if (curValue >= nextValue) l++; else break;
    }
    r = max(r, m + 1);
    if (r >= n - 1) break;
    while (r + 1 < n - 1) {
      ll curValue = abs((a[n - 1] - a[r]) - (a[r] - a[m]));
      ll nextValue = abs((a[n - 1] - a[r + 1]) - (a[r + 1] - a[m]));
      if (curValue >= nextValue) r++; else break;
    }
    vector<ll> x = {a[l], a[m] - a[l], a[r] - a[m], a[n - 1] - a[r]};
    sort(x.begin(), x.end());
    result = min(result, x.back() - x[0]);
  }
  cout << result << endl;

  return 0;
}
