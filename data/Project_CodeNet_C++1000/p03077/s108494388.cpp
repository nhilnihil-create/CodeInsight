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
  long long N;
  cin >> N;
  long long A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;

  long long ta = (N + A - 1) / A;
  long long tb;
  if (B >= A)
  {
    tb = ta + 1;
  }
  else
  {
    tb = (N + B - 1) / B + 1;
  }

  long long tc;
  if (C >= B || C >= A)
  {
    tc = tb + 1;
  }
  else
  {
    tc = (N + C - 1) / C + 2;
  }

  long long td;
  if (D >= C || D >= B || D >= A)
  {
    td = tc + 1;
  }
  else
  {
    td = (N + D - 1) / D + 3;
  }

  long long te;
  if (E >= D || E >= C || E >= B || E >= A)
  {
    te = td + 1;
  }
  else
  {
    te = (N + E - 1) / E + 4;
  }

  cout << te << endl;

  return 0;
}
