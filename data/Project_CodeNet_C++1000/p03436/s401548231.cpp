#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int xs[4] = {-1, 1, 0, 0};
int ys[4] = {0, 0, -1, 1};
int Ds[50][50];

int main() {
  int H,W;
  string Cs[50];
  cin >> H >> W;
  rep(i, H) cin >> Cs[i];
  queue<pair<int, int>> Q;
  Q.push(make_pair(0, 0));
  rep(i, 50) fill(Ds[i], Ds[i]+50, -1);
  Ds[0][0] = 0;
  int d;
  bool flag = false;
  while(Q.size()) {
    auto V = Q.front(); Q.pop();
    d = Ds[V.first][V.second];
    if(V.first == H-1 && V.second == W-1) {
      flag = true;
      break;
    }
    rep(i, 4) {
      int dx = xs[i]; int dy = ys[i];
      int nx = V.second+dx; int ny = V.first+dy;
      if(0<=nx && nx<W && 0<=ny && ny<H && Cs[ny][nx]=='.' && Ds[ny][nx]==-1) {
        Q.push(make_pair(ny, nx));
        Ds[ny][nx] = d+1;
      }
    }
  }
  int sum = 0;
  rep(i, H) rep(j, W) if(Cs[i][j]=='.') sum++;
  if(flag) cout << sum - d - 1<< endl;
  else cout << -1 << endl;
  return 0;
}
