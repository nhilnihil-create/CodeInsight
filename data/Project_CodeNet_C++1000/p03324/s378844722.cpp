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
  int D, N;
  cin >> D >> N;

  if (N == 100)
  {
    N = 101;
  }

  rep(i, D)
  {
    N *= 100;
  }

  cout << N << endl;

  return 0;
}
