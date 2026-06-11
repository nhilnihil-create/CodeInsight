// Code for A - Ferris Wheel
#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a >= 13) {
    cout << b << endl;
    return 0;
  }

  if (a >= 6) {
    cout << b / 2 << endl;
    return 0;
  }

  cout << 0 << endl;

	return 0;
}
