#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<int> t(5);
  rep(i, 5) cin >> t[i];
  vector<int> s(5);
  rep(i, 5) s[i] = 10 + (t[i] - 1) / 10 * 10;
  int ans = 1e5;
  rep(i, 5) {
    int u = 0;
    rep(j, 5) {
      if (j == i) u += t[j];
      else u += s[j];
    }
    ans = min(ans, u);
  }
  cout << ans << endl;
  return 0;
}