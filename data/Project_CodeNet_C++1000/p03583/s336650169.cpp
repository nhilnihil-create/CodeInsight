#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans;
  cin >> N;
  for (int h = 1; h <= 3500; h++)
  {
    for (int n = 1; n <= 3500; n++)
    {
      if ((4 * h * n) - (N * n) - (N * h) != 0 && (N * h * n) % ((4 * h * n) - (N * n) - (N * h)) == 0)
      {
        if ((N * h * n) / ((4 * h * n) - (N * n) - (N * h)) > 0)
        {
          int64_t w = (N * h * n) / ((4 * h * n) - (N * n) - (N * h));
          cout << h << ' ' << n << ' ' << w << endl;
          return 0;
        }
      }
    }
  }
}