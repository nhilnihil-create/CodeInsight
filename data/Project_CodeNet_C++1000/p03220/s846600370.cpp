#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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
  int T, A;
  cin >> T >> A;

  int pos = 0;
  double mn = -1.0;

  rep(i, N)
  {
    int h;
    cin >> h;

    double diff = std::abs(A - (T - h * (double)0.006));
    if (mn < 0 || mn > diff)
    {
      pos = i;
      mn = diff;
    }
  }

  cout << pos + 1 << endl;

  return 0;
}
