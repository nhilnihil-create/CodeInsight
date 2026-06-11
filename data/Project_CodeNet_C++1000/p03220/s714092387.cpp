#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  double n, t, a;
  cin >> n >> t >> a;
  vector<double> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int ans = 0;
  double temp = 1e9;
  for (int i = 0; i < n; i++) {
    double x = t - h[i] * 0.006;
    if (abs(a - x) < temp) {
      temp = abs(a - x);
      ans = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
