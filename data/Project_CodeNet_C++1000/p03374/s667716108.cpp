#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> x(n + 2, 0), v(n + 2, 0);
  for (int i = 1; i <= n; i++) cin >> x[i] >> v[i];
  x[n + 1] = k;
  vector<long long> c(n + 1, 0), C(n + 1, 0), d(n + 1, 0), D(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    c[i] = c[i - 1] + v[n + 1 - i] - (x[n + 2 - i] - x[n + 1 - i]);
    C[i] = C[i - 1] + v[n + 1 - i] - ((x[n + 2 - i] - x[n + 1 - i]) << 1);
    d[i] = d[i - 1] + v[i] - (x[i] - x[i - 1]);
    D[i] = D[i - 1] + v[i] - ((x[i] - x[i - 1]) << 1);
  }
  for (int i = 1; i <= n; i++) {
    c[i] = max(c[i], c[i - 1]);
    C[i] = max(C[i], C[i - 1]);
    d[i] = max(d[i], d[i - 1]);
    D[i] = max(D[i], D[i - 1]);
  }
  long long ret = 0;
  for (int i = 0; i <= n; i++) {
    ret = max(ret, c[i] + D[n - i]);
    ret = max(ret, C[i] + d[n - i]);
  }
  cout << ret << '\n';
  return 0;
}
