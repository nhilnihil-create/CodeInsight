#include <iostream>
#include <string>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int x = n / 2;
  int y = n / 2 + 1;
  if (n % 2 == 0) {
    cout << x * x;
  }
  else {
    cout << x * y;
  }
}
