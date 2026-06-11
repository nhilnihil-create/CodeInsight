#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ma = a[n - 1], res = a[0];
  for (int i = 0; i < n - 1; i++) {
    if (min(abs(a[i] - ma / 2), abs(a[i] - (ma + 1) / 2)) < min(abs(res - ma / 2), abs(res - (ma + 1) / 2))) {
      res = a[i];
    }
  }
  cout << ma << ' ' << res << '\n';
}