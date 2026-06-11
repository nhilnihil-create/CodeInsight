#include <iostream>
using namespace std;

int main()
{
  int H, W;
  string board[50];

  cin >> H >> W;
  for (int i = 0; i < H; i++)
    cin >> board[i];

  int xd[4] = {1, 0, -1, 0};
  int yd[4] = {0, 1, 0, -1};
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (board[i][j] == '.') continue;
      int cnt = 0;
      for (int k = 0; k < 4; k++)
      {
        int xnum = j + xd[k];
        int ynum = i + yd[k];
        if (xnum < 0 || W <= xnum) continue;
        if (ynum < 0 || H <= ynum) continue;
        if (board[ynum][xnum] == '#') cnt++;
      }
      if (cnt == 0)
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
