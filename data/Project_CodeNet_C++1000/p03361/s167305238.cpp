#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
  rep(i, h){
    rep(j, w){
      if(s.at(i).at(j) == '#'){
        bool f = false;
        rep(k, 4){
          int ni = i + dy[k], nj = j + dx[k];
          if(nj < 0 || w <= nj || ni < 0 || h <= ni) continue;
          if(s.at(ni).at(nj) == '#') f = true;
        }
        if(f == false){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}