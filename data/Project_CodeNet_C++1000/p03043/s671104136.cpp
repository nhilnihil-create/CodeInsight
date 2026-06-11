#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  double n, k;
  cin >> n >> k;
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    long double x = 1.0 / n;
    int cnt = i;
    while (k > cnt) {
      cnt *= 2;
      x /= 2;
    }
    ans += x;
  }
  cout << fixed << setprecision(11);
  cout << ans << '\n';
  return 0;
}