#include <iostream>

using namespace std;

int main() {

  int a, b, c;
  cin >> a >> b;
  cout << (b % a == 0) * (a + b) + (b % a != 0) * (b - a);
  return 0;
}
