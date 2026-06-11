#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int gcd(int x, int y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    auto r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main() {
  int a, ans;
  cin >> ans >> ans;
  while (cin >> a) ans = gcd(ans, a);
  cout << ans << endl;
}
