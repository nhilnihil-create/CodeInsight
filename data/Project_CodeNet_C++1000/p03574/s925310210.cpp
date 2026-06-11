#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int x_offset[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
const int y_offset[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int main()
{
  int H, W;
  cin >> H >> W;
  vector <string> S(H);
  vector <string> ans(H);
  for (int i = 0; i < H; i++) {
    cin >> S[i];
    ans[i] = S[i];
  }

  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      if (ans[h][w]=='#') continue;
      int boms = 0;
      for (int i = 0; i < 8; i++) {
        int x = w + x_offset[i];
        int y = h + y_offset[i];
        if (x < 0) continue;
        if (y < 0) continue;
        if (x >= W) continue;
        if (y >= H) continue;
        if (S[y][x]=='#') boms++;
      }
      ans[h][w] = (char)boms + '0';
    }
  }
  for (int h = 0; h < H; h++) {
    cout << ans[h] << endl;
  }
  return 0;
}
