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
  int h, w, d;
  cin >> h >> w >> d;
  vector<vector<int>> a(h, vector<int>(w));
  vector<pair<int, int>> vp(h*w);
  rep(i, h){
    rep(j, w){
      int in;
      cin >> in;
      in--;
      vp.at(in) = make_pair(i, j);
      a.at(i).at(j) = in;
    }
  }
  vector<vector<int>> cost(d, vector<int>());
  rep(i, d){
    cost.at(i).push_back(0);
    int bf = i;
    for(int j = 1; ; j++){
      int nw = i + d*j;
      if(nw >= h*w) break;
      int add = abs(vp.at(nw).first - vp.at(bf).first) + abs(vp.at(nw).second - vp.at(bf).second);
      int bk = cost.at(i).back();
      cost.at(i).push_back(add+bk);
      bf = nw;
    }
  }
  // rep(i, d){
  //   for(auto j : cost.at(i)){
  //     cerr << j << " ";
  //   }
  //   cerr << endl;
  // }
  int q;
  cin >> q;
  rep(_q, q){
    int l, r;
    cin >> l >> r;
    l--; r--;
    int pos = l % d;
    l /= d;
    r /= d;
    // cerr << l << " " << r << " " << pos << endl;
    cout << cost.at(pos).at(r) - cost.at(pos).at(l) << endl;
  }
  return 0;
}