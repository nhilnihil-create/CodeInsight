#include <bits/stdc++.h>
using namespace std;

int main() {
  double n, m, d; cin >> n >> m >> d;
  cout << fixed << setprecision(10);
  if (d == 0) cout << (m - 1) / n << endl;
  else cout << 2 * (n - d) * (m - 1) / (n * n) << endl;
}