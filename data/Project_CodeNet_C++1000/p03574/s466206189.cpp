#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
#define all(a) a.begin(), a.end() 
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> mp(h, vector<char> (w));
  rep(i, h) rep(j, w) cin >> mp[i][j];
  
  int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
  
  rep(i, h) {
    rep(j, w) {
      if(mp[i][j] == '.') {
        int bombs = 0;
        rep(k, 8) {
          int ni = i+dx[k];
          int nj = j+dy[k];
          
          if(ni<0 || h <= ni) continue;
          if(nj<0 || w <= nj) continue;
          if(mp[ni][nj] == '#') ++bombs;
        }
        mp[i][j] = char(bombs+'0');
      }
    }
  }
  
  rep(i, h) {
    rep(j, w) cout << mp[i][j];
    cout << endl;
  }
  
  return 0;
}
