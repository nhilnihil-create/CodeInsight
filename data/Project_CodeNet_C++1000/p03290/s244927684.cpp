#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, G;
  cin >> D >> G;
  int p[D], c[D], foo, bar, tmp, ans = INT_MAX;
  for (int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
  }
  for (int i = 0; i < pow(2, D); i++) {
    foo = bar = 0;
    for (int j = 0; j < D; j++) {
      if (((i >> j) & 1) > 0) {
        foo += p[j] * 100 * (j + 1) + c[j];
        bar += p[j];
      }
    }
    if (foo < G) {
      for (int j = D - 1; j >= 0 && foo < G; j--) {
        if (((i >> j) & 1) == 0) {
          tmp = min((G - foo - 1) / (100 * (j + 1)) + 1, p[j] - 1);
          foo += tmp * 100 * (j + 1);
          bar += tmp;
        }
      }
    }
    if (bar < ans && foo >= G) {
      ans = bar;
    }
  }
  cout << ans;
  return 0;
}