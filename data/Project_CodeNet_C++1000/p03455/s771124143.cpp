#include <iostream>

using namespace std;

int main(void) {
  int a, b, tmp;
  cin >> a >> b;

  tmp = a * b;
  (tmp % 2 == 0) ? cout << "Even" << endl : cout << "Odd" << endl;
  return 0;
}