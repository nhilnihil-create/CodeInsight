#include <iostream>

using namespace std;

int main() {
  int n;
  bool f = false;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'Y') {
      f = true;
      break;
    }
  }
  if (f) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
  return 0;
}
