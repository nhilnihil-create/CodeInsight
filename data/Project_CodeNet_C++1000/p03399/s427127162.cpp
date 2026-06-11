#include<iostream>
using namespace std;
int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a + c <= b + d && a + c <= a + d && a + c <= b + c)
    cout << a + c;
  else if(a + d <= b + c && a + d <= a + c && a + d <= b + d)
    cout << a + d;
  else if(b + c <= a + d && b + c <= b + d && b + c <= a + c)
    cout << b + c;
  else if(b + d <= a + c && b + d <= a + d && b + d <= b + c)
    cout << b + d;
  return 0;
}
