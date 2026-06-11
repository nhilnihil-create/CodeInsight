#include<iostream>
using namespace std;
int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  if(n * a >= b)
    cout << b;
  else
    cout << n * a;
  return  0;
}