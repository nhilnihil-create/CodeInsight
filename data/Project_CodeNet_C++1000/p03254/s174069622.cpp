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
  int n; cin >> n;
  int x; cin >> x;
  vector<ll> a(n); for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= x) {
      result++;
      x -= a[i];
    }
  }
  if (result == n && x != 0) result--;
  cout << result << endl;

  return 0;
}
