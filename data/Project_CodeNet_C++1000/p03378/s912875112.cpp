#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // Toll Gates
  int n, m, x; cin >> n >> m >> x;
  int lc=0, rc=0;
  rep(i,m) {
     int ai; cin >> ai;
     if (ai < x) lc++;
     else rc++;
  }
  cout << min(lc,rc) << endl;
  return 0;
}