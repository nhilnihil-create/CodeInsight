#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main() {
  int H, W; cin >> H >> W;
  string s[H]; rep(i,H) cin >> s[i];
  int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int dj[] = {1, 1, 1, 0, 0, -1, -1, -1};
  
  rep(i, H) {
    rep(j, W) {
      if (s[i][j] == '#') {
        cout << "#";
        continue;
      }
      int c = 0;
      rep(k, 8) {
        int ik = i + di[k];
        int jk = j + dj[k];
        if (ik < 0 || ik >= H || jk < 0 || jk >= W) continue;
        if (s[ik][jk] == '#') c++;
      }
      cout << c;
    }
    cout << endl;
  }
}
