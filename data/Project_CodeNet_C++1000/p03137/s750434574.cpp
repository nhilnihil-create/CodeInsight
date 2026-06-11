#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  rep(i, m) cin >> x[i];

  sort(x.begin(), x.end());
  vector<int> g(m-1);
  rep(i, m-1) g[i] = x[i+1] - x[i];
  sort(g.begin(), g.end());
  int ans = 0;
  rep(i, m-n) ans += g[i];
  cout << ans << endl;
  return 0;
}