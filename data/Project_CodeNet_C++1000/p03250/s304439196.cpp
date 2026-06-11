#include<iostream>
using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if(a >= b && a >= c)
    cout << 10 * a + b + c;
  if(b > a && b >= c)
    cout << 10 * b + a + c;
  if(c > a && c > b)
    cout << 10 * c + a + b;
  return 0;
}