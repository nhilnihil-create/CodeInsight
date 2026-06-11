#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w, n; cin >> h >> w >> n;
  vector<set<int>> P(w);
  rep(i, n) {
    int x, y; cin >> x >> y;
    x--; y--;
    P[y].insert(x);
  }
  int mn = inf;
  int lb = 0;
  rep(i, w) {
    P[i].insert(h);
    if(lb+1 > h) break;
    mn = min(*lower_bound(all(P[i]), lb+1), mn);
    if(i != w-1) while(lb+1<=h && P[i+1].count(lb+1)) lb++;
    lb++;
  }
  cout << mn << endk;
  return 0;
}
