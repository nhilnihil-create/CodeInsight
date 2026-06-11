#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) FOR(i, n, 0);

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  int n; cin >> n;
  if(n == 1) {
    cout << "Yes" << endl;
    cout << 2 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  if(n == 2) {
    cout << "No" << endl;
    return 0;
  }
  int tmp = n;
  int i=1;
  while(tmp > 0) {
    tmp -= i;
    i++;
  }
  if(tmp != 0) {
    cout << "No" << endl;
    return 0;
  }
  vector<vector<int>> a(i);
  a[0].pb(1);
  a[1].pb(1);
  int now = 2;
  FOR(j, 2, i) {
    REP(k, j) {
      a[k].pb(now);
      a[j].pb(now);
      now++;
    }
  }
  // REP(j, i) {
  //   REP(k, a[j].size()) {
  //     cout << a[j][k] << " ";
  //   }
  //   cout << endl;
  // }

  cout << "Yes" << endl;
  cout << a.size() << endl;
  REP(i, a.size()) {
    cout << a[i].size() << " ";
    REP(j, a[i].size()) {
      if(j != a[i].size()-1) cout << a[i][j] << " ";
      else cout << a[i][j] << endl;
    }
  }
}
