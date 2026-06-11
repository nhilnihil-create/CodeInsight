#include <iostream>
using namespace std;

int main() {
  long x, y;
  cin >> x >> y;
  int a;
  
  if (x % y == 0) {
    a = -1;
  } 
  else {
    a = x;
  }
  cout << a << endl;
}
