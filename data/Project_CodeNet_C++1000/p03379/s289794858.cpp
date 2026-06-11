#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), xx(n);
  rep(i, n) cin >> x[i];
  xx = x;
  sort(xx.begin(), xx.end());
  rep(i, n) {
    if (x[i] <= xx[n / 2 - 1]) {
      cout << xx[n / 2] << endl;
    } else {
      cout << xx[n / 2 - 1] << endl;
    }
  }
  return 0;
}
