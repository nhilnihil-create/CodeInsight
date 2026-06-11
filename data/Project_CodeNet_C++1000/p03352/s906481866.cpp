#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
  int X;
  cin >> X;
  int ans = 1;
  for (int i = 2; i <= (int)sqrt(X); i++) {
    int exp = i;
    for(;;) {
      exp *= i;
      if (exp > X) break;
      ans = max(ans, exp);
    }
  }
  cout << ans << endl;
  return 0;
}