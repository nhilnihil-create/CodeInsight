#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a % 2) {
    if (b % 2) {
      cout << "Odd";
    } else cout << "Even";
  } else cout << "Even";
}
  