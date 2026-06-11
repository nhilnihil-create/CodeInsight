#include <iostream>
using namespace std;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
int main() {
  int in(N);
  int in(C);

  int D[C][C];
  rep(i, C) rep(j, C)
    cin >> D[i][j];

  int count[3][30];
  rep(i, 3) rep(j, C)
    count[i][j] = 0;
  rep(i, N) rep(j, N) {
    int c; cin >> c;
    --c;
    ++count[(i+j)%3][c];
  }

  int ans = 2e9;
  rep(a, C) rep(b, C) rep(c, C) {
    if (a == b || b == c || a == c)
      continue;
    int tmp = 0;
    rep(i, C) {
      tmp += D[i][a] * count[0][i];
      tmp += D[i][b] * count[1][i];
      tmp += D[i][c] * count[2][i];
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;



  return 0;
}
