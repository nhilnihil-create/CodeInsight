#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int D, G;
  cin >> D >> G;

  vector<int> p(D);
  vector<int> c(D);
  rep(i, D)
  {
    cin >> p[i];
    cin >> c[i];
  }

  vector<vector<int>> score(D + 1);
  rep(i, D + 1)
  {
    score[i].resize(1001, 0);
  }

  int problems = 0;
  rep(i, D)
  {
    for (int j = 0; j <= problems; j++)
    {
      int s = score[i][j];
      for (int k = 0; k <= p[i]; k++)
      {
        if (k == p[i])
          s += c[i];
        score[i + 1][j + k] = std::max(score[i + 1][j + k], s + 100 * (i + 1) * k);
      }
    }

    problems += p[i];
  }

  rep(i, 1001)
  {
    if (score[D][i] >= G)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
