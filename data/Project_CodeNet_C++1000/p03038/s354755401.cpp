#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> b(m), c(m);
  vector<pair<int, int>> p;
  rep(i,m) {
    cin >> b[i] >> c[i];
    p.emplace_back(c[i], b[i]);
  }

  sort(a.begin(), a.end());
  sort(p.begin(), p.end());

  ll ans = 0;
  rep(i,n){
    if (p.empty()) {
      ans += a.back();
      a.pop_back();
      continue;
    }
    if (a.back() >= p.back().first){
      ans += a.back();
      a.pop_back();
    } else {
      ans += p.back().first;
      p.back().second--;
      if (p.back().second == 0) p.pop_back();
    }
  }

  cout << ans << endl;
  return 0;
}
