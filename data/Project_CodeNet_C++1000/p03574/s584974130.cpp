#include <iostream>
using namespace std;

int main()
{
  int H, W;
  string input[55];

  cin >> H >> W;
  for (int i = 0; i < H; i++)
  {
    cin >> input[i];
    for (int j = 0; j < W; j++)
      if (input[i][j] == '.') input[i][j] = '0';
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (input[i][j] == '#') continue;
      if (i != 0     &&               input[i - 1][j]     == '#') input[i][j]++;
      if (j != 0     &&               input[i][j - 1]     == '#') input[i][j]++;
      if (i != 0     && j != 0     && input[i - 1][j - 1] == '#') input[i][j]++;
      if (i != H - 1 &&               input[i + 1][j]     == '#') input[i][j]++;
      if (j != W - 1 &&               input[i][j + 1]     == '#') input[i][j]++;
      if (i != H - 1 && j != W - 1 && input[i + 1][j + 1] == '#') input[i][j]++;
      if (i != 0     && j != W - 1 && input[i - 1][j + 1] == '#') input[i][j]++;
      if (i != H - 1 && j != 0     && input[i + 1][j - 1] == '#') input[i][j]++;
    }
  }
  for (int i = 0; i < H; i++)
    cout << input[i] << endl;
}
