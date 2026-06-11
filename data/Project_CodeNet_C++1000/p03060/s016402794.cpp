#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> v(n), c(n);
  rep(i,n) cin >> v[i];
  rep(i,n) cin >> c[i];

  int x, cost, ans=0, toku;
  for (int bit = 0; bit < (1<<n); bit++) {
    x = 0; cost = 0;toku = 0;
    for (int i = 0; i < n; i++) {
      if (bit&(1<<i)) {
        x += v[i];
        cost += c[i];
      }
    }
    toku = x - cost;
    ans = max(ans, toku);
  }

  cout << ans << endl;
  return 0;

}