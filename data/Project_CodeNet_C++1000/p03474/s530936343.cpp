#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  
  for (int i = 0; i < a + b + 1; i++) {
    if (i == a) {
      if (s.at(i) != '-') {
        cout << "No" << endl;
        break;
      }
    }
    else if (i != a + b) {
      if (s.at(i) == '-') {
        cout << "No" << endl;
        break;
      }
    }
    else {
      if (s.at(i) != '-') {
        cout << "Yes" << endl;
      }
      else {
        cout << "No" << endl;
      }
    }
  }
}
