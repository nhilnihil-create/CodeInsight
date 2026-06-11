#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int s = a + b;
  if (s % 2 == 1) {
    s++;
  }
  cout << s / 2 << endl;
  return 0;
}
