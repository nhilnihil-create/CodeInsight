#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (b >= a) cout << a << '\n';
  else cout << a - 1 << '\n';
  return 0;
}