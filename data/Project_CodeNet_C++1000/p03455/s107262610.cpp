#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  const char* r[] = {
    "Even", "Odd"
  };
  cout << r[(a * b) & 1] << endl;

  return 0;
}
