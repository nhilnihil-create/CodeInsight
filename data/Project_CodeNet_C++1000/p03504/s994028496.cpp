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
  int n, c;
  cin >> n >> c;
  vector<vector<pair<int, int>>> vp(c, vector<pair<int, int>>());
  rep(i, n){
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    vp.at(c).push_back(make_pair(s, t));
  }
  rep(i, c) sort(vp.at(i).begin(), vp.at(i).end());
  vector<int> imos(1e5+5, 0);
  rep(i, c){
    int sz = vp.at(i).size();
    rep(j, sz){
      if(j+1 == sz || vp.at(i).at(j+1).first != vp.at(i).at(j).second) imos.at(vp.at(i).at(j).second)--;
      if(j == 0 || vp.at(i).at(j-1).second != vp.at(i).at(j).first) imos.at(vp.at(i).at(j).first - 1)++;
    }
  }
  int mx = 0, now = 0;
  rep(i, imos.size()){
    now += imos.at(i);
    mx = max(mx, now);
  }
  cout << mx << endl;
  return 0;
}