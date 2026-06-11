#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i < (n); i++)
const int INF = 1e9;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> g(h);
  rep(i,h) cin >> g[i];
  vector<vector<int>> cnt(h, vector<int>(w,INF));
  rep(i,h) rep(j,w) {
    if (g[i][j] == '#') continue;
    int c = 0;
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        int ni = i + di;
        int nj = j + dj;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (g[ni][nj] == '#') c++;
      }
    }
    cnt[i][j] = c;
  }
  rep(i,h) {
    rep(j,w) {
      if (cnt[i][j] == INF) cout << '#';
      else cout << cnt[i][j];
    }
    cout << endl;
  }
}