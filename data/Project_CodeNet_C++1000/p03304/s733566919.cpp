#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  double n, m, d;
  cin >> n >> m >> d;

  if (d == 0) {
    cout << fixed << setprecision(9) << (m - 1) / n << '\n';
  } else {
    cout << fixed << setprecision(9) << 2 * (n - d) / (n * n) * (m - 1) << '\n';
  }

  return 0;
}