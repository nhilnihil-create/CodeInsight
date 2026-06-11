#include <iostream>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int l = a + b;
  int r = c + d;
  if (l > r) {
    cout << "Left";
  } else if (l < r) {
    cout << "Right";
  } else {
    cout << "Balanced";
  }
  cout << endl;
  return 0;
}
