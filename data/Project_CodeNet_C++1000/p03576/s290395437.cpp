#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define int long long
 
signed main() {
  int n, k;
  cin >> n >> k;
  int x[n], y[n];
  int xcpy[n], ycpy[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    xcpy[i] = x[i];
    ycpy[i] = y[i];
  }
  sort(x, x + n);
  sort(y, y + n);
  int ans = LLONG_MAX;
  for (int xl = 0; xl < n; xl++) {
    for (int xr = xl + 1; xr < n; xr++) {
      for (int yl = 0; yl < n; yl++) {
        for (int yr = yl + 1; yr < n; yr++) {
          int count = 0;
          for (int i = 0; i < n; i++) {
            if (x[xl] <= xcpy[i] && xcpy[i] <= x[xr] && y[yl] <= ycpy[i] && ycpy[i] <= y[yr]) {
              count++;
            }
          }
          if (count >= k) {
            int res = (x[xr] - x[xl]) * (y[yr] - y[yl]);
            ans = min(ans, res);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}