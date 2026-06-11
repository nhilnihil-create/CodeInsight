#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int n, m, c, a;
  cin >> n >> m >> c;
  vector<int> b(m);
  int ans = 0;
  rep(i, m) cin >> b[i];
  rep(i, n) {
    int total = 0;
    rep(j, m) {
      cin >> a;
      total += a * b[j];
    }
    if (total + c > 0) ans++;
  }
  cout << ans << '\n';
  return 0;
}