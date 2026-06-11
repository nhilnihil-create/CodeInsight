#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n);
  bool ok = 1;
  for (auto&& e : h) {
    cin >> e;
    if (ok && e != 0) ok = 0;
  }
  int cnt = 0;
  while (!ok) {
    int maxh = *max_element(h.begin(), h.end());
    ok = 1;
    for (int i = 0; i < n; i++) {
      if (h[i] == maxh) {
        if (h[i + 1] != maxh || i == n - 1) {
          cnt++;
        }
        h[i]--;
        if (h[i] != 0) ok = 0;
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
