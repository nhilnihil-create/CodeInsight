#include <iostream>

using namespace std;

int main() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  if ((a == b && b == c) || (b == c && c == d)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
