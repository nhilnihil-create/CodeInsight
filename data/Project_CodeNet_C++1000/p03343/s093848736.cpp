#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = (int) 2e9;
  for (int bound : a) {
    vector<int> c;
    multiset<int> s;
    for (int i = 0; i <= n; i++) {
      if (i == n || a[i] < bound) {
        sort(c.begin(), c.end());
        for (int j = 0; j <= (int) c.size() - k; j++) {
          s.insert(c[j]);
        }
        c.clear();
      } else {
        c.push_back(a[i]);
      }
    }
    if ((int) s.size() < q) {
      continue;
    }
    auto it = s.begin();
    for (int i = 0; i < q - 1; i++) {
      it++;
    }
    ans = min(ans, *it - bound);
  }
  cout << ans << '\n';
  return 0;
}