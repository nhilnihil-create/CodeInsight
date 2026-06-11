#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if (n % k != 0) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
}
