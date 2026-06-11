#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n, a;
  cin >> n;
  int ans = 0;
  rep(i, 0, n) {
    cin >> a;
    ans += __builtin_ctz(a);
  }
  cout << ans << endl;

  return 0;
}