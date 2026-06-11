#include <iostream>
#include <string>
using namespace std;

int main() {
  int p, w, g, y, n;
  char s;
  p = 0, w = 0, g = 0, y = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == 'P') {
      p = 1;
    }
    else if (s == 'W') {
      w = 1;
    }
    else if (s == 'G') {
      g = 1;
    }
    else if (s == 'Y') {
      y = 1;
    }
  }

  if ((p == 1 && w == 1) && (w == 1 && g == 1) && (g == 1 && y == 1) && (y == 1 && p == 1)) {
    cout << "Four" << endl;
  }
  else {
    cout << "Three" << endl;
  }
}