#include <iostream>

using namespace std;

int main()
{
  int x, y;
  cin >> x >> y;
  if(x % y == 0)
    cout << -1;
  else
    cout << x;
  return 0;
}
