#include <iostream>

using namespace std;

int main() {
  int a, b, x;
  cin >> a >> b >> x;
  if (x < a) {
    cout << "NO" << endl;
  } else if (a + b < x) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
