#include <iostream>

using namespace std;

int main() {
  int r, d, x;
  cin >> r >> d >> x;
  for (int i = 2001; i <= 2010; ++i) {
    x = x * r - d;
    cout << x << endl;
  }
}