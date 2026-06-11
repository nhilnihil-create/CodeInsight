#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= 3500; i++) {
    for (int j = 1; j <= 3500; j++) {
      if (4*i*j-n*i-n*j > 0) {
        if (((n*i*j) >= (4*i*j-n*i-n*j))&&((n*i*j)%(4*i*j-n*i-n*j) == 0)) {
          ans = (n*i*j)/(4*i*j-n*i-n*j);
          cout << i << ' ' << j << ' ' << ans << endl;
          break;
        }
      }
    }
    if (ans > 0) {
      break;
    }
  }
}