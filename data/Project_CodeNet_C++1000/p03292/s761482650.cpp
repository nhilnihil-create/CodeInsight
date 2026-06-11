#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int maxdif = max({abs(a - b), abs(b - c), abs(c - a)});
  cout << abs(a - b) + abs(b - c) + abs(a - c) - maxdif << endl;
  return 0;
}