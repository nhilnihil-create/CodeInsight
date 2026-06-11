#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, t;
  cin >> a >> b >> t;
  int sum = 0, s = 0, mul = 1;
  while (s <= t) {
    s += mul * a;
    if (s > t) break;
    sum += b;
  }
  cout << sum << endl;
  return 0;
}
