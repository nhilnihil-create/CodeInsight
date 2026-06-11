#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int h,w; cin >> h >> w;
  int flg = 1;
  char tizu[h][w];

  rep(i,h)rep(j,w) cin >> tizu[i][j];
  rep(i,h)rep(j,w) {
    if(tizu[i][j]=='#') {
      int dx1 = i+1;
      int dx2 = i-1;
      int dy1 = j+1;
      int dy2 = j-1;
      if (dx1>=0 && dx1 < h && tizu[dx1][j]=='#' || dx2>=0 && dx2 < h && tizu[dx2][j]=='#' || dy1>=0 && dy1 < w && tizu[i][dy1]=='#' || dy2>=0 && dy2 < w && tizu[i][dy2]=='#' ) {
        continue;
      } else {
        flg = 0;
        break;
      }
    }
  }
  if (flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}