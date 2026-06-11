#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  const int K = 29;
  int ans = 0;
  for (int k = 0; k < K; k++) {
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = b[i] % (1 << (k + 1));
    }
    sort(c.begin(), c.end());

    long long cnt = 0, l, r;
    for (auto v : a) {
      v %= (1 << (k + 1));
      l = lower_bound(c.begin(), c.end(), (1 << k) - v) - c.begin();
      r = lower_bound(c.begin(), c.end(), (1 << k) * 2 - v) - c.begin();
      cnt += (r - l);
      l = lower_bound(c.begin(), c.end(), (1 << k) * 3 - v) - c.begin();
      r = lower_bound(c.begin(), c.end(), (1 << k) * 4 - v) - c.begin();
      cnt += (r - l);
    }
    if (cnt & 1) ans += (1 << k);
  }

  cout << ans << '\n';

  return 0;
}
