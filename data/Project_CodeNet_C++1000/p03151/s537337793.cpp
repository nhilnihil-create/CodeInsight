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
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<ll> wins;
  ll sumLosses = 0;
  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= b[i]) {
      wins.push_back(a[i] - b[i]);
    } else {
      sumLosses += b[i] - a[i];
      result++;
    }
  }
  sort(wins.rbegin(), wins.rend());
  for (int x : wins) {
    if (sumLosses > 0) {
      result++;
      sumLosses -= x;
    }
  }

  if (sumLosses > 0) result = -1;

  cout << result << endl;

  return 0;
}
