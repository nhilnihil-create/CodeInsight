#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int N = (1 << n);
  vector<int> a(N), ret(N);
  vector<pair<int, int>> M(N), m(N);
  for (int bs = 0; bs < N; bs++) cin >> a[bs];
  M[0] = make_pair(a[0], 0);
  m[0] = make_pair(0, 0);
  for (int bs = 1; bs < N; bs++) {
    set<pair<int, int>> rpr;
    for (int i = 0; i < n; i++) if ((bs >> i) & 1) {
      int cs = bs - (1 << i);
      rpr.emplace(M[cs]);
      rpr.emplace(m[cs]);
    }
    rpr.emplace(make_pair(a[bs], bs));
    auto it = rpr.end();
    M[bs] = *(--it);
    m[bs] = *(--it);
    ret[bs] = M[bs].first + m[bs].first;
  }
  for (int bs = 2; bs < N; bs++) {
    ret[bs] = max(ret[bs], ret[bs - 1]);
  }
  for (int bs = 1; bs < N; bs++) {
    cout << ret[bs] << endl;
  }
  return 0;
}