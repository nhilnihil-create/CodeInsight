#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <limits>
#include <math.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if (k == 0) {
    long long ans = pow((long long)n, 2LL);
    cout << ans << endl;
    return 0;
  }

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int p = n / i;
    int r = n - p * i;
    ans += (max(i - k, 0) * p) + max(r + 1 - k, 0);
  }
  cout << ans << endl;
  return 0;
}
