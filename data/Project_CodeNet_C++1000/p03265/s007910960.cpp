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
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int diff_x = x2 - x1;
  int diff_y = y2 - y1;

  int x3 = x2 - (y2 - y1);
  int y3 = y2 + (x2 - x1);
  int x4 = x3 - (y3 - y2);
  int y4 = y3 + (x3 - x2);

  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

  return 0;
}
