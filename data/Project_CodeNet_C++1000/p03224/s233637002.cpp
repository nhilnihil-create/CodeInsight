#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;

int main() {
  int n;
  cin>>n;
  int k = 0;
  bool ok = false;
  REP(i,2*n+1) {
    if (i*(i+1) > 2*n) break;
    if (i*(i+1) == 2*n) {
      k = i+1;
      ok = true;
    }
  }
  if (!ok) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<vector<int>> g(k, vector<int>(k));
  int cnt = 0;
  REP(i,k)REP(j,i) {
    g[i][j] = ++cnt;
    g[j][i] = cnt;
  }
  cout << k << endl;
  REP(i,k) {
    cout << (k-1);
    REP(j,k) {
      if (i==j) continue;
      cout << ' ' << g[i][j];
    }
    cout << endl;
  }
  return 0;
}
