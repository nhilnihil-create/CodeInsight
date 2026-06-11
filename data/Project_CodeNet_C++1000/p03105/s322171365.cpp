#include <iostream>
using namespace std;
int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  int ans = B / A;
  if (ans > C) ans = C;
  cout << ans << endl;
  return 0;
}
