#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  cin >> a >> b;
  c = "asd";
  int count = 0;
  char x = 0;
  for (int i = 0; i < a.size(); i++) {
    c = a.substr(i, a.size()-1) + a.substr(0, i);
    if (c == b) {
      count++;
    }
    if (a == b) {
      count++;
      break;
    }
  }
  if (count == 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
      