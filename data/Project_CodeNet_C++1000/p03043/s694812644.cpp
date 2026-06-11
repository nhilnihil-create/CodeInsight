#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

  int n, k;
  cin >> n >> k;

  int maxTimes = 0;
  int max = 1;
  while (true)
  {
    if (max >= k)
    {
      break;
    }

    maxTimes++;
    max = max << 1;
  }

  if (maxTimes == 0)
  {
    cout << 1;
  }
  else
  {
    long long allPattern = (1 << maxTimes) * n;
    long long winPattern = 0;

    vector<int> times(n+1, 0);
    for (int i = 1; i < n+1; i++)
    {

      int tmp = i;
      while (true)
      {
        if (tmp >= k)
        {
          break;
        }

        times[i]++;
        tmp = tmp << 1;
      }
    }

    for (int i = 1; i < n+1; i++)
    {
      winPattern += 1 << (maxTimes - times[i]);
    }

    cout << fixed << setprecision(12) << (double)winPattern / (double)allPattern;
  }

  return 0;
}