#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int maxx = max(x, y);
  int64_t min_sum = 10000000000000;
  int64_t sum = 0;
  rep(i, maxx + 1) {
    sum = 2 * i * c;
    if (i <= x) {
      sum += a * (x - i);
    }
    if (i <= y) {
      sum += b * (y - i);
    }
    if (min_sum > sum) {
      min_sum = sum;
    }
  }
  cout << min_sum << endl;
}