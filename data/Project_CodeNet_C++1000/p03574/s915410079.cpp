#include <iostream>
#include <string>

using namespace std;

int main()	{
  int h, w;
  cin >> h >> w;
  char field[h][w];
  for (int i = 0; i < h; i++)	{
	for (int j = 0; j < w; j++)	{
      cin >> field[i][j];
    }
  }
  for (int i = 0; i < h; i++)	{
    for (int j = 0; j < w; j++)	{
      if (field[i][j] == '#')	{
        cout << field[i][j];
        continue;
      }
      int mineCount = 0;
      for (int x = i - 1; x < i + 2; x++)	{
        for (int y = j - 1; y < j + 2; y++)	{
          if (x >= 0 && y >= 0 && x < h && y < w && field[x][y] == '#')	{
            mineCount++;
          }
        }
      }
      cout << mineCount;
    }
    cout << endl;
  }
  return 0;
}