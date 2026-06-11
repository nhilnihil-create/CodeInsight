#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int xy = max(x, y);
  int res = 1e9;
  for (int i = 0; i <= xy; i++)
  {
    int temp;
    temp = c * i * 2;
    temp += a * max(x - i, 0);
    temp += b * max(y - i, 0);
    res = min(res, temp);
  }
  cout << res << endl;
}