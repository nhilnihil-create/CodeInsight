#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, h, maxA = 1;
  cin >> n >> h;
  int b[n];
  for (int a, i = 0; cin >> a >> b[i]; ++i) {
    maxA = max(maxA, a);
  }
  sort(b, b + n);
  for (int i = 0; i < n; ++i) {
    if (b[i] >= maxA) {
      int result = 0;
      for (int j = n - 1; j >= i && h > 0; --j) {
        h -= b[j];
        ++result;
      }
      if (h > 0) {
        result += (h - 1) / maxA + 1;
      }
      cout << result;
      break;
    }
  }
  return 0;
}