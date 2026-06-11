#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n;

  int p = 0, w = 0, g = 0, y = 0, c = 0;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "P") {
      if (++p == 1) {
        c++;
      }
    } if (s == "W") {
      if (++w == 1) {
        c++;
      }
    } if (s == "G") {
      if (++g == 1) {
        c++;
      }
    } if (s == "Y") {
      if (++y == 1) {
        c++;
      }
    }
  }
  
  if (c == 3) {
    cout << "Three" << endl;
  } else if (c == 4) {
    cout << "Four" << endl;
  }
}