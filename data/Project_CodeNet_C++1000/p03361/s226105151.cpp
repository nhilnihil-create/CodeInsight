#include <bits/stdc++.h>
using namespace std;
bool Grid[55][55];

int main()
{
  int h, w;
  cin >> h >> w;
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      char c;
      cin >> c;
      Grid[i][j] = c == '#';
    }
  }
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      if (!Grid[i][j])
        continue;
      if (!Grid[i - 1][j] && !Grid[i + 1][j] && !Grid[i][j - 1] && !Grid[i][j + 1])
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}