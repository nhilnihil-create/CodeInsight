#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  rep(i, m) {
    cin >> l[i] >> r[i];
    --l[i];
    --r[i];
  }

  vector<int> imos(n + 1, 0);
  rep(i, m) {
    ++imos[l[i]];
    --imos[r[i] + 1];
  }
  rep(i, n) imos[i+1] += imos[i];
  int ans = 0;
  rep(i, n+1) if (imos[i] == m) ++ans;
  cout << ans << endl;
  return 0;
}