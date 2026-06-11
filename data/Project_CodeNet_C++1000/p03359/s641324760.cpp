#include<iostream>
using namespace std;
int main()
{
  int a, b;
  cin >> a >> b;
  if(a - 1 >= 0 && b - 1 >= 0 && b >= a)
    cout << a;
  else cout << a - 1;
  return 0;
}
