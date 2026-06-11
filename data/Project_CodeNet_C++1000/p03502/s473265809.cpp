#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int m = n;
  int s = 0;
  while (m > 0) {
    s += m % 10;
    m /= 10;
  }
  if (n % s == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
