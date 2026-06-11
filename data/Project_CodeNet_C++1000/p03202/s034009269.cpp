#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
LL p = 1000000007ll;

int main(void)
{
  LL n;
  cin >> n;
  vector<int> a(n);
  for(auto &x:a) cin >> x;
  LL l = 0;
  LL r = n;
  while(r-l>1) {
    LL piv = (l+r+1) / 2;
    vector<pair<int,int>> str;
    bool lpiv = false;
    for(auto x:a) {
      bool more = false;
      while(!str.empty() && str.back().first > x) {
        more = true;
        str.pop_back();
      }
      if(more && piv == 1) {
        lpiv = true;
        break;
      }
      if(str.empty() || str.back().first < x) {
        if(more) str.emplace_back(x,2);
        else str.emplace_back(x,1);
      } else {
        LL updatePos = x;
        while(!str.empty() && str.back().first == updatePos && str.back().second == piv) {
          --updatePos;
          str.pop_back();
        }
        if(updatePos == 0) {
          lpiv = true;
          break;
        }
        if(!str.empty() && str.back().first == updatePos) {
          ++str.back().second;
        } else {
          str.emplace_back(updatePos,2);
        }
        if(updatePos != x) str.emplace_back(x,1);
      }
    }
    if(lpiv) l = piv;
    else r = piv;
  }
  cout << r << endl;
  return 0;
}
