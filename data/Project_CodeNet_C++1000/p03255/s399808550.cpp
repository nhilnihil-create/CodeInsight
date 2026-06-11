#include <bits/stdc++.h>
using namespace std;
vector<long long> acm;
int n, shoot;
long long cost (int k) {
  long long ret = (long long)(n + k) * shoot;
  int trans = 5;
  ret += (acm[k] - acm[0]) * trans;
  for (int i = 1; i * k < n; i++, trans+= 2) {
    ret += (acm[k * (i + 1)] - acm[k * i]) * trans;
    if (ret >= (long long)1e17) {
      return (long long)1e18;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> shoot;
  vector<int> pos(n);
  acm.resize(2 * n, 0);
  for (int i = 0; i < n; i++) {
    cin >> pos[i];
  }
  sort(pos.begin(), pos.end());
  reverse(pos.begin(), pos.end());
  for (int i = 1; i < 2 * n; i++) {
    acm[i] = acm[i - 1];
    if (i <= n) {
      acm[i] += pos[i - 1];
    }
  }
  long long minv = 1e18;
  for (int k = 1; k <= n; k++) {
    minv = min(minv, cost(k));
  }
  cout << minv << '\n';
  return 0;
}