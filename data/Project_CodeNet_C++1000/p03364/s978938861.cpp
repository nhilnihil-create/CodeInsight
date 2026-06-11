#include <bits/stdc++.h>
using namespace std;
char Ga[610][610];
char Gb[310][310];

int main()
{
  int64_t N, ans = 0;
  cin >> N;
  char c;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> c;
      Ga[i][j] = Ga[i + N][j] = Ga[i][j + N] = Ga[i + N][j + N] = c;
    }
  }
  for (int a = 0; a < N; a++)
  {
    bool ok = 1;
    for (int i = a + 1; i < N + a; i++)
    {
      for (int j = 0; j < (i - a); j++)
      {
        if (Ga[i][j] != Ga[j + a][i - a]) // i-a, j-b -> j-b, i-a -> j-b+a, i-a+b
        {
          ok = 0;
          break;
        }
      }
      if (!ok)
        break;
    }
    if (ok)
      ans++;
  }
  cout << ans * N << endl;
}
