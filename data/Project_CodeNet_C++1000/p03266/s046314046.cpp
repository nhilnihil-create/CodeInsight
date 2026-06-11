#include <iostream>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;

  long long a = n / k;
  long long b = (n + (k / 2)) / k;

  if (k & 1) {
    cout << a * a * a << endl;
  } else {
    cout << a * a * a + b * b * b << endl;
  }

  return 0;
}
