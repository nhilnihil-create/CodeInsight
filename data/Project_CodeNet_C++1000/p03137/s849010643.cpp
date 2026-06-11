#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> x(m),diff(m-1);
  rep(i,m) cin >> x[i];
  sort(x.begin(),x.end());
  rep(i,m-1) diff[i] = x[i+1] - x[i];
  sort(diff.begin(),diff.end());
  ll ans = 0;
  rep(i,m-n) ans += diff[i];
  cout << ans << endl;
}