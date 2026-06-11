#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, Y;
  bool flag = false;
  cin >> N >> Y;

  for (int i = N; i >= 0; i--)
  {
    for (int j = N - i; j >= 0; j--)
    {
      for (int k = N - i - j; k >= 0; k--)
      {
        if ((10000 * i) + (5000 * j) + (1000 * k) == Y && i + j + k == N)
        {
          cout << i << " " << j << " " << k << endl;
          flag = true;
          break;
        }
      }
      if (flag)
      {
        break;
      }
    }
    if (flag)
    {
      break;
    }
  }
  if (!flag)
  {
    cout << "-1 -1 -1" << endl;
  }
}
