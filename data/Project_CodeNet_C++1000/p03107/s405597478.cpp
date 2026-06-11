#include <iostream>

using namespace std;

int main() {
  int a = 0, b = 0;
  char c;
  while (cin >> c) {
    if (c == '0')
      ++a;
    else
      ++b;
  }
  cout << a + b - abs(a - b) << endl;
}