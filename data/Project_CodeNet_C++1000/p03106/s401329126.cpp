#include <iostream>

using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int cnt = 0;
  for (int i = a; 1 <= i; --i) {
    cnt += a / i * i == a && b / i * i == b;
    if (cnt != k)
      continue;
    cout << i << endl;
    break;
  }
}