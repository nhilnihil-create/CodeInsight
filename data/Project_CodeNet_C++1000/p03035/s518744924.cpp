#include <iostream>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  if (A > 12) {
    cout << B << endl;
  } else if (A >= 6 && A <= 12) {
    cout << (B >> 1) << endl;
  } else {
    cout << 0 << endl;
  }
  
  return 0;
}
