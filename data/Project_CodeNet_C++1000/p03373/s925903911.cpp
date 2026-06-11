#include <iostream>

#include <cmath>

using std::cin;
using std::cout;
using std::endl;

using std::min;

static int
solve(int A, int B, int C, int X, int Y)
{
  if (A + B <= C * 2)
  {
    return A * X + B * Y;
  }
  int xy = min(X, Y);
  return min(C * 2, A) * (X - xy) + min(C * 2, B) * (Y - xy) + C * xy * 2;
}

int
main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  cout << solve(A, B, C, X, Y) << endl;
  return 0;
}
