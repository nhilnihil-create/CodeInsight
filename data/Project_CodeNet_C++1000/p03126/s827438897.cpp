#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> l(m, 0);
  rep(i, n) {
    int k;
    cin >> k;
    vector<int> a(k);
    rep(i, k) cin >> a[i];
    rep(i, k) --a[i];
    rep(i, k) ++l[a[i]];
  }
  int ans = 0;
  rep(i, m) if (l[i] == n) ++ans;
  cout << ans << endl;
  return 0;
}