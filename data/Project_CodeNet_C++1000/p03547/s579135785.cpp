#include<iostream>
using namespace std;
int main()
{
  char x, y;
  char A = 10, B = 11, C = 12, D = 13, E = 14, F = 15;
  cin >> x >> y;
  if(x == y)
    cout << "=";
  if(x > y)
    cout << ">";
  if(x < y)
    cout << "<";
  return 0;
}
