#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<bool> can(n, true);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        int si = (i + k) % n;
        int sj = (j - k + n) % n;
        if (a[i][j] != a[si][sj]) {
          can[(i - sj + n) % n] = 0;
        }
      }
    }
  }
  cout << n * accumulate(can.begin(), can.end(), 0) << '\n';
  return 0;
}
