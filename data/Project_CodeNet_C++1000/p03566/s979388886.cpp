#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int INF = 1e9;

int main(){
  int n;
  cin >> n;
  int t[n + 4];
  t[0] = 0;
  t[1] = 0;
  for (int i = 2; i <= n + 1; i++) {
    cin >> t[i];
    t[i] += t[i - 1];
  }
  t[n + 2] = t[n + 1];
  t[n + 3] = t[n + 1];
  int v[n + 2];
  v[0] = 0;
  v[1] = 0;
  for (int i = 2; i <= n + 1; i++) {
    cin >> v[i];
  }
  v[n + 2] = 0;
  v[n + 3] = 0;
  double left = 0;
  double ans = 0;
  for (double x = 0.5; x <= t[n + 1]; x += 0.5) {
    double right = 1e9;
    for (int i = 1; i <= n + 3; i++) {
      double vv;
      if (x < t[i - 1]) {
        vv = -x + t[i - 1] + v[i];
      } else if (x >= t[i - 1] && x <= t[i]) {
        vv = v[i];
      } else {
        vv = x + v[i] - t[i];
      }
      right = min(right, vv);
    }
    //cout << left << " " << right << endl;
    ans += (left + right) * 0.25;
    left = right;
  }
  cout << setprecision(20) << ans << endl;
  return 0;
}
