#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n), v(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  for (int i = 0; i < n; ++i)
    v[i] = a[i] - b[i];

  sort(v.begin(), v.end());

  int last = n - 1, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] >= 0)
      continue;

    int j = last;
    while (v[j] > 0) {
      int x = min(-v[i], v[j]);
      v[i] += x;
      v[j] -= x;
      if (v[j] > 0)
        break;
      if (v[i] < 0)
        --j;
    }

    if (v[i] < 0) {
      cout << -1 << endl;
      return 0;
    }

    ans += 1 + (last - j);
    last = j;
  }

  if (ans > 0)
    ++ans;
  cout << ans << endl;
}