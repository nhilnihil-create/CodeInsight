#include <iostream>
using namespace std;

int main()
{
  int a, b, c;

  cin >> a >> b >> c;

  int res = (a == b) ? c : (b == c) ? a : b;
  cout << res << endl;
  return 0;
}
