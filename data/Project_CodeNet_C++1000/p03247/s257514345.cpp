#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  bool type;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    bool odd = (x[i] + y[i]) & 1;
    if (!i) {
      type = odd;
    } else if (type != odd) {
      cout << -1 << "\n";
      return 0;
    }
  }
  if (!type) {
    for (int i = 0; i < n; ++i) {
      ++x[i];
    }
  }
  vector<int> d(31);
  for (int i = 0; i < 31; ++i) {
    d[i] = 1 << i;
  }
  vector<string> ans(n, string(31, '.'));
  for (int i = 0; i < n; ++i) {
    for (int j = 30; ~j; --j) {
      if (abs(x[i] + d[j]) < (1 << j) - abs(y[i])) {
        ans[i][j] = 'L';
        x[i] += d[j];
      } else if (abs(x[i] - d[j]) < (1 << j) - abs(y[i])) {
        ans[i][j] = 'R';
        x[i] -= d[j];
      } else if (abs(y[i] + d[j]) < (1 << j) - abs(x[i])) {
        ans[i][j] = 'D';
        y[i] += d[j];
      } else {
        ans[i][j] = 'U';
        y[i] -= d[j];
      }
    }
  }
  if (!type) {
    d.push_back(1);
    for (int i = 0; i < n; ++i) {
      ans[i].push_back('L');
    }
  }
  cout << d.size() << "\n";
  for (int i = 0; i < (int) d.size(); ++i) {
    if (i) {
      cout << " ";
    }
    cout << d[i];
  }
  cout << "\n";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}
