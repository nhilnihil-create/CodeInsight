#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  double ans = 0.0;
  for (int i = 1; i <= n; i++) {
    int val = i;
    double prob = 1.0;
    while(val < k) {
      val *= 2;
      prob /= 2.0;
    }
    ans += prob;
  }
  ans /= n;
  cout << fixed << setprecision(10) << ans << '\n';
}