#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int h, w;
  bool ans = true;
  cin >> h >> w;
  vector<vector<char>> s(h + 2, vector<char>(w + 2, '.'));
  for (int i = 1; i < h + 1; i++)
  {
    for (int j = 1; j < w + 1; j++)
    {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i < h + 1; i++)
  {
    for (int j = 1; j < w + 1; j++)
    {
      if (s[i][j] == '#' && s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i + 1][j] == '.' && s[i][j + 1] == '.')
      {
        ans = false;
      }
    }
  }
  if (ans)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
