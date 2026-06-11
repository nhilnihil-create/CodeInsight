#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  map<int,int> fc;
  rep(i,n) {
    int ki; cin >> ki;
    rep(j,ki) {
      int aij; cin >> aij;
      fc[aij]++;
    }
  }
  int ans = 0;
  for (auto p : fc) {
    if (p.second >= n) ans++;
  }
  cout << ans << endl;
  return 0;
}