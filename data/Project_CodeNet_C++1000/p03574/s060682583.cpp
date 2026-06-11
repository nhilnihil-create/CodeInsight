#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  vector<string> ans(h);
  rep (i, h) cin >> v[i];
  rep (i, h){
    rep (j, w){
      if (v[i][j] == '#'){
        ans[i] += "#";
      } else {
        int count = 0;
        for (int k = -1; k < 2; ++k){
          if (i+k < 0) continue;
          if (i+k >= h) continue;
          for (int l = -1; l < 2; ++l){
            if (j+l < 0) continue;
            if (j+l >= w) continue;
            if (v[i+k][j+l] == '#'){
              ++count;
            }
          }
        }
        ans[i] += to_string(count);
      }
    }
  }
  rep (i, h){
    cout << ans[i] << endl;
  }
  return 0;
}