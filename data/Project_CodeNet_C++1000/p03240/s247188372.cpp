#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N;
  cin >> N;

  vector<int> x(N);
  vector<int> y(N);
  vector<int> h(N);
  rep(i, N)
  {
    cin >> x[i] >> y[i] >> h[i];
  }

  rep(i, 101)
  {
    rep(j, 101)
    {
      int diff = -1;

      bool found = true;
      rep(k, N)
      {
        if (h[k] == 0)
        {
          continue;
        }
        int tmp = h[k] + std::abs(i - x[k]) + std::abs(j - y[k]);
        if (diff == -1)
          diff = tmp;
        if (diff != tmp)
        {
          found = false;
          break;
        }
      }

      if (found)
      {
        int X = i;
        int Y = j;
        int H;
        bool correct = true;
        rep(k, N)
        {
          if (h[k] != 0)
          {
            H = h[k] + std::abs(X - x[k]) + std::abs(Y - y[k]);
            break;
          }
        }
        rep(k, N)
        {
          if (h[k] != std::max(0, H - std::abs(X - x[k]) - std::abs(Y - y[k])))
          {
            correct = false;
            break;
          }
        }
        if (correct)
        {
          cout << X << " " << Y << " " << H << endl;
          return 0;
        }
      }
    }
  }

  return 0;
}
