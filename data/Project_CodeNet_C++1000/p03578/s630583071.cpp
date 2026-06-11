#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  map<int, int> d;
  rep(i,n) {
    int di; cin >> di;
    d[di]++;
  }
  int m; cin >> m;
  string ans = "YES";
  rep(i,m) {
    int ti; cin >> ti;
    if (d.count(ti) && d[ti] != 0)  d[ti]--;
    else { ans = "NO"; break; }
  }
  cout << ans << endl;
  return 0;
}