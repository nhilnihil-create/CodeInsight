#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  VI a(n), b(n); for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  const int N = 30;
  lint res = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] | k) == k) res += b[i];
  }
  for (int i = 0; i < N; i++) {
    lint tmp = 0;
    if (!(k & 1 << i)) continue;
    int x = (k & ~((1 << i) - 1)) - 1;
    for (int j = 0; j < n; j++) {
      if ((a[j] | x) == x) tmp += b[j];
    }
    res = max(res, tmp);
  }
  cout << res << '\n';
  return 0;
}