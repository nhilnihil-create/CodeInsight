#include <iostream>

using namespace std;

int main () {
  int n, a, b;
  cin >> n >> a >> b;

  if (a % 2 == b % 2) {
    cout << "Alice" << '\n';
  } else {
    cout << "Borys" << '\n';
  }
}
