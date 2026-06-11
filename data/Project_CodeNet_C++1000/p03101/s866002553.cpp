#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

void solve(){
  int H, W, h, w; cin >> H >> W >> h >> w;
  bool a[H][W];
  for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) a[i][j] = true;
  for(int i = 0; i < h; i++) for(int j = 0; j < W; j++) a[i][j] = false;
  for(int i = 0; i < w; i++) for(int j = 0; j < H; j++) a[j][i] = false;

  int ans = 0;
  for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) if(a[i][j] == true) ans++;
  cout << ans << endl;

  return;
}

int main(){
  solve();
  return 0;
}
