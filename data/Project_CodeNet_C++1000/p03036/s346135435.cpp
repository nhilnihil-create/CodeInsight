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
  int r, D, x;
  cin >> r >> D >> x;

  rep(i, 10)
  {
    x = r * x - D;
    cout << x << endl;
  }

  return 0;
}
