#include <bits/stdc++.h>
using namespace std;
vector<int> a;
bool cmp (int i, int j) {
  return a[i] < a[j];
}
int main() {
  int n;
  cin >> n;
  int N = (1 << n);
  a.resize(N);
  vector<int> ret(N), M(N), m(N);
  for (int bs = 0; bs < N; bs++) cin >> a[bs];
  M[0] = 0;
  m[0] = 0;
  vector<int> rpr;
  for (int bs = 1; bs < N; bs++) {
    rpr.clear();
    rpr.push_back(bs);
    for (int i = 0; i < n; i++) if ((bs >> i) & 1) {
      int cs = bs ^ (1 << i);
      rpr.push_back(M[cs]);
      rpr.push_back(m[cs]);
    }
    sort(rpr.begin(), rpr.end(), cmp);
    rpr.resize(unique(rpr.begin(), rpr.end()) - rpr.begin());
    auto it = rpr.end();
    M[bs] = *(--it);
    m[bs] = *(--it);
    ret[bs] = a[M[bs]] + a[m[bs]];
  }
  int now = 0;
  for (int bs = 1; bs < N; bs++) {
    now = max(now, ret[bs]);
    cout << now << endl;
  }
  return 0;
}