#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  for (long h = 1; h <= 3500; h++) {
    for (long n = 1; n <= 3500; n++) {
      long double w = (N * h * n) / (double) (4 * h * n - N * n - N * h);
      if (w < 0) continue;
      if (w == (long) w) return cout << h << " " << n << " " << (long) w << "\n", 0;
    }
  }
}