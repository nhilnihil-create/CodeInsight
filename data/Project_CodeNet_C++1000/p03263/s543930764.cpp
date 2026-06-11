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
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h){
    rep(j, w){
      int in;
      cin >> in;
      a.at(i).at(j) = in;
    }
  }
  vector<tuple<int, int, int,int>> ans;
  rep(i, h){
    rep(j, w){
      if(a.at(i).at(j) % 2 != 0){
        if(j != w-1){
          a.at(i).at(j+1)++;
          ans.push_back(make_tuple(i, j, i, j+1));
        }else if(i != h-1){
          a.at(i+1).at(j)++;
          ans.push_back(make_tuple(i, j, i+1, j));
        }
      }
    }
  }
  cout << ans.size() << endl;
  for(auto t : ans){
    int y1, x1, y2, x2;
    tie(y1, x1, y2, x2) = t;
    cout << y1+1 << " " << x1+1 << " " << y2+1 << " " << x2+1 << endl;
  }
  return 0;
}