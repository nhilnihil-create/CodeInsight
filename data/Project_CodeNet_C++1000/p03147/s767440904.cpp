#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];

  auto nfind = [&](int i) {
    for (int j = i; j < n; j++) {
      if (h[j] > 0) return j;
    }
    return -1;
  };

  int ans = 0;
  while (true) {
    int l = -1, r = n - 1;
    for (int i = 0; i < n; i++) {
      if (h[i] > 0) {
        l = i;
        break;
      }
    }
    for (int i = l; i < n; i++) {
      if (h[i] == 0) {
        r = i - 1;
        break;
      }
    }
    if (l == -1) break;
    ans++;
    for (int i = l; i <= r; i++) h[i]--;
  }

  cout << ans << endl;
}
