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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> c(h, vector<int>(w));
  rep(i, h){
    rep(j, w){
      int a;
      cin >> a;
      c.at(i).at(j) = a;
    }
  }

  vector<tuple<int, int, int, int>> ans;
  rep(i, h){
    rep(j, w){
      if(c.at(i).at(j) % 2 != 0){
        if(j != w-1){
          ans.push_back(make_tuple(i+1, j+1, i+1, j+2));
          c.at(i).at(j+1)++;
        }else if(i != h-1){
          ans.push_back(make_tuple(i+1, j+1, i+2, j+1));
          c.at(i+1).at(j)++;
        }
      }
    }
  }

  cout << ans.size() << endl;
  for(auto t : ans){
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << endl;
  }
  return 0;
}