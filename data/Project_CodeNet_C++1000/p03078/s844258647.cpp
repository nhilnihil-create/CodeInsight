#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
#define rep(i, n) for(int i=0;i<n;i++)
int main() {
  int x, y, z, K;
  cin >> x >> y >> z >> K;
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  vector<ll> ans;
  rep(i, x) rep(j, y) rep(k, z) {
    if((i+1) * (j+1) * (k+1) <= K) ans.emplace_back(a[i]+b[j]+c[k]);
    else break;
  }
  sort(ans.rbegin(), ans.rend());
  rep(i, K) cout << ans[i] << endl;
  return 0;
}

