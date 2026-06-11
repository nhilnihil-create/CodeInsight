#include<iostream>
using namespace std;
int main()
{
  int n, a, b, c;
  cin >> n;
  a = n / 100;
  b = (n / 10) % 10;
  c = n % 10;
  if(a == 1)
    a = 9;
  else a = 1;
  if(b == 1)
    b = 9;
  else b = 1;
  if(c == 1)
    c = 9;
  else c = 1;
  cout << 100 * a + 10 * b + c;
  return 0;
}