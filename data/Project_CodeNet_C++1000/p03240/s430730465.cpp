#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<tuple<int, int, int>> vt(n);
  rep(i, n){
    int x, y, h;
    cin >> x >> y >> h;
    vt.at(i) = make_tuple(x, y, h);
  }
  sort(vt.begin(), vt.end(),
    [](const auto &l, const auto &r){
      return get<2>(l) > get<2>(r);
    }
  );
  rep(i, 101){
    rep(j, 101){
      int d = abs(get<0>(vt.at(0)) - j) + abs(get<1>(vt.at(0)) - i);
      int top = d + get<2>(vt.at(0));
      if(top <= 0) continue;
      bool f = false;
      rep2(k, 1, n){
        int dd = abs(get<0>(vt.at(k)) - j) + abs(get<1>(vt.at(k)) - i);
        int tt = max(top - dd, 0);
        if(tt != get<2>(vt.at(k))){
          f = true;
          break;
        }
      }
      if(f == false){
        cout << j << " " << i << " " << top << endl;
        return 0;
      }
    }
  }
  return 0;
}