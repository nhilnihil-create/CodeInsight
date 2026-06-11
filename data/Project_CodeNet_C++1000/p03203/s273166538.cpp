#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int h,w,n;
  cin>>h>>w>>n;
  vector<pair<int,int>> v;
  REP(i,n) {
    int x,y;
    cin>>x>>y;
    v.emplace_back(x,y);
  }
  sort(ALL(v));
  int mx = 1;
  int mn = h;
  int oldx = 1;
  REP(i,n) {
    int x, y;
    tie(x, y) = v[i];
    int newmx = mx + (x - oldx);
    if (y > newmx) continue;
    if (y == newmx) {
      mx = newmx - 1;
      oldx = x;
      continue;
    }
    mn = x-1;
    break;
  }
  cout << mn << endl;
  return 0;
}
