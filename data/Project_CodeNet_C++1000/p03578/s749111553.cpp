#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, m;
  cin >> n;

  vector<ll> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];

  cin >> m;
  vector<ll> t(m);
  for (int i = 0; i < m; i++) cin >> t[i];

  multiset<ll> p;
  for (int i = 0; i < n; i++) p.insert(d[i]);

  bool ans = true;
  for (int i = 0; i < m; i++) {
    auto f = p.find(t[i]);
    if (f == p.end()) {
      ans = false;
      break;
    }
    p.erase(f);
  }
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
