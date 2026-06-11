#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i=0; i<h; ++i) cin >> s[i];

  int x[8] = {1, 0, -1, 0, 1, -1, -1, 1};
  int y[8] = {0, 1, 0, -1, 1, 1, -1, -1};
  for(int i=0; i<h; ++i) {
    for(int j=0; j<w; ++j) {
      if(s[i][j] == '#') continue;
      int count = 0;
      for(int k=0; k<8; ++k) {
        int ni = i + y[k];
        int nj = j + x[k];
        if(ni < 0 || ni >= h) continue;
        if(nj < 0 || nj >= w) continue;
        if(s[ni][nj] == '#') count++;
      }
      s[i][j] = char(count + '0');
    }
  }
  for(int i=0; i<h; ++i) cout << s[i] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
