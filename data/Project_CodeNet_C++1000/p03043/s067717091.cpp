#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n, k;
  cin >> n >> k;


  double ans = 0.0;
  for (int i = 1; i <= n; ++i) {
    double temp = 1.0 / n;
    int j = i;
    while (j < k) {
      j *= 2;
      temp *= 0.5;
    }
    ans += temp;
  }

  cout << fixed << setprecision(10);
  cout << ans << endl;

  return 0;
}