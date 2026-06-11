#include<iostream>
using namespace std;
int main()
{
  int a, b;
  cin >> a >> b;
  if(a > b)
  {
      if(a - 1 >= b)
        cout << 2 * a - 1;
      else
        cout << a + b;
  }
  else
    if(a < b)
  {
      if(b - 1 >= a)
        cout << 2 * b - 1;
      else
        cout << a + b;
  }
  else
    cout << a + b;
  return 0;
}