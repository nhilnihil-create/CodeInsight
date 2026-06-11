#include <bits/stdc++.h>
using namespace std;
bool Grid[100][100]; // 0: white, 1: black

void init()
{
  for (int i = 0; i < 100; i++)
  {
    for (int j = 50; j < 100; j++)
    {
      Grid[i][j] = 1;
    }
  }
}

int main()
{
  int64_t A, B;
  cin >> A >> B;
  A--, B--;
  init();
  for (int i = 1; i <= 98; i += 2)
  {
    for (int j = 1; j <= 48; j += 2)
    {
      if (B)
      {
        Grid[i][j] = 1;
        B--;
      }
    }
  }
  for (int i = 1; i <= 98; i += 2)
  {
    for (int j = 51; j <= 98; j += 2)
    {
      if (A)
      {
        Grid[i][j] = 0;
        A--;
      }
    }
  }
  cout << 100 << ' ' << 100 << endl;
  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
      cout << (Grid[i][j] ? '#' : '.');
    }
    cout << endl;
  }
}
