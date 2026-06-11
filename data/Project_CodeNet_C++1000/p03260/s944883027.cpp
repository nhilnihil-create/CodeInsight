#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  bool flag = false;
  for (int i = 1; i <= 3; ++i) {
    int tmp = a * b * i;
    if (tmp % 2 == 1)
      flag = true;
  }
  cout << (flag ? "Yes" : "No") << endl;
}
