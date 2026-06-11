#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  rep (i, h) cin >> v[i];

  bool ans = true;
  int h2[4] = {-1, 1, 0, 0};
  int w2[4] = {0, 0, 1, -1};
  rep (i, h){
    rep (j, w){
      if (v[i][j] == '#'){
        bool f = false;
        rep (k, 4){
          if ((i+h2[k] < 0) || (i+h2[k] >= h)) continue;
          if ((j+w2[k] < 0) || (j+w2[k] >= w)) continue;
          if (v[i+h2[k]][j+w2[k]] == '#') f = true;
        }
        if (f == false) ans = false;
      }
    }
  }
  if (ans == true) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}