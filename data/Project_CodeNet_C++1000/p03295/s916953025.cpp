#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    a[i] = {y, x};
  }
  int ans = 0;
  int pos = -1;
  sort(a.begin(), a.end());
  for (int i = 0; i < m; ++i) {
    if (a[i].second > pos) {
      ++ans;
      pos = a[i].first - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
