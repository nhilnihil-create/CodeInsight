#include <iostream>

using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  for (int i = 0; i < k && i + a <= b; i++) {
    cout << a + i << endl;
  }
  int j = b - k + 1;
  if (b - k < a + k) {
    j = a + k;
  }
  for (; j <= b; j++) {
    cout << j << endl;
  }
  return 0;
}
