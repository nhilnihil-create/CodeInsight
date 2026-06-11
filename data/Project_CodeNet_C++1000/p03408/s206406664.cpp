#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b = 0, c = 100;
  vector<string> d(200);
  for (cin >> a; a; a--) cin >> d.at(b++);
  for (cin >> b; b--;) cin >> d.at(c++);
  for (;;) {
    b = 0;
    string e = "";
    for (c = 0; c < 200; c++) {
      if (e == "" && d.at(c) != "") e = d.at(c);
      if (e != "" && e == d.at(c)) {
        d.at(c) = "";
        if (c > 99) b--;
        else b++;
      }
    }
    if (e == "") break;
    if (b > a) a = b;
  }
  cout << a;
}