#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a + b + c, x;
  x = max({a, b, c});
  sum -= x;
  cout << x * 10 + sum << endl;
  return 0;
}