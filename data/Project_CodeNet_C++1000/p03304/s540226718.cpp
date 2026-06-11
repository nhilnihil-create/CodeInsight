#include <bits/stdc++.h>
using namespace std;
int main () {
  double n, m, d;
  cin >> n >> m >> d;
  double ans = (n - d) * (m - 1) / (n * n);
  if(d != 0)ans *= 2;
  cout << setprecision(100) << ans << endl;
  return 0;
}