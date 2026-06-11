#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int d[1001] = {0};
  for (int i = 1; i <= 1000; i++) {
    d[i] = d[i - 1] + i;
  }
  int diff = b - a;
  for (int i = 0; i <= 1000; i++) {
    if (d[i + 1] - d[i] == diff) {
      cout << d[i] - a << endl;
      break;
    }
  }

  return 0;
}
