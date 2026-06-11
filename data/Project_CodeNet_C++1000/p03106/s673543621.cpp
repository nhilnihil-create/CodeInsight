#include <iostream>

using namespace std;

int GCD(int a, int b) {
  while (a) {
    int tmp = a;
    a = b % a;
    b = tmp;
  }
  return b;
}


int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int gcd = GCD(a, b);
  int cnt = 0;
  for (int i = 1; i <= gcd; ++i) {
    if (gcd % i) continue;
    cnt++;
    if (cnt == k) {
      cout << gcd / i << endl;
      return 0;
    }
  }
}
