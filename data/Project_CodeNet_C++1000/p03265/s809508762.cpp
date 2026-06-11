#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int dx = x2 - x1, dy = y2 - y1;
  int x3 = x2 - dy, y3 = y2 + dx, x4 = x1 - dy, y4 = y1 + dx;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  return 0;
}