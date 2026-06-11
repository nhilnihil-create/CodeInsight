#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;
  int m = 1;
  int stop = sqrt(x);
  for (int i = 2; i <= stop; i++) {
    int b = i;
    while (b * i <= x) {
      b *= i;
    }
    m = max(m, b);
  }
  cout << m << endl;
  return 0;
}
