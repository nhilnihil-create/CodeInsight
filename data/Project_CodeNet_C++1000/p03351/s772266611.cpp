#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool ans = false;
  if (abs(a-c)<=d) ans = true;
  if (abs(a-b)<=d && abs(b-c)<=d) ans = true;
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
