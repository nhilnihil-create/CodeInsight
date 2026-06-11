#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;

  vector<int> t(n + 1);
  vector<int> x(n + 1);
  vector<int> y(n + 1);

  for (int i = 1; i <= n; i++) cin >> t[i] >> x[i] >> y[i];

  for (int i = 0; i <= n; i++) {
    ll dist = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    ll td = t[i] - t[i - 1];
    ll rest = td - dist;
    if (rest < 0 || rest % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
