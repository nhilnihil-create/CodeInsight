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
  int n, m;
  cin >> n >> m;
  vector<int> p = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<pair<int, char>> vp;
  rep(i, m){
    int in;
    cin >> in;
    vp.push_back(make_pair(p.at(in-1), in + '0'));
  }
  vector<string> dp(n+10, "x");
  dp.at(0) = "";
  rep(i, n){
    if(dp.at(i) == "x") continue;
    rep(j, vp.size()){
      int pf; char ps;
      tie(pf, ps) = vp.at(j);
      int nxi = i + pf;
      string nxs = dp.at(i);
      nxs.push_back(ps);
      sort(nxs.rbegin(), nxs.rend());
      bool f = false;
      if(dp.at(nxi) == "x") f = true;
      else if(dp.at(nxi).size() < nxs.size()) f = true;
      else if(dp.at(nxi).size() == nxs.size() && dp.at(nxi) < nxs) f = true;
      if(f == true) dp.at(nxi) = nxs;
    }
  }
  cout << dp.at(n) << endl;
  return 0;
}