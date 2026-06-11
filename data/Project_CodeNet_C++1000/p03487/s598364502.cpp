#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  map<ll, int> m;
  for (int i = 0; i < n; i++) {
    if (m.count(a[i]) == 0) m[a[i]] = 0;
    m[a[i]]++;
  }
  int ans = 0;
  for (auto e : m) {
    if (e.first < e.second) {
      ans += e.second - e.first;
    } else if (e.first > e.second) {
      ans += e.second;
    }
  }
  cout << ans << endl;
}
