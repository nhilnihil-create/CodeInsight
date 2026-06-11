#include <string>
#include <math.h>
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, x, y;
  cin >> a;
  if (a == 1) {
    cout << "Hello World";
  }
  else if (a == 2) {
    cin >> x >> y;
    cout << x + y;
  }
}