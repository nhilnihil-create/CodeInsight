#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ina(x, n) rep(x_i,n) cin>>x[x_i]

const int INF = (1<<30);

int main() {
  int n, ans = INF; cin >> n;
  vector<int> d(n); ina(d,n);
  sort(d.begin(), d.end());
  int lr[2] = { 0, 0 };
  rep(i,n) {
    ans = min(ans, d[i] - lr[i&1]);
    lr[i&1] = d[i];
  }
  ans = min(ans, 24 - lr[0] - lr[1]);
  cout << ans << endl;
  return 0;
}
