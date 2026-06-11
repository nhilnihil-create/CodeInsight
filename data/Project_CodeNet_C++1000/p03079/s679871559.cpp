#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string str = "Yes";
  if (a != b) {
    str = "No";
  } else if (b != c) {
    str = "No";
  } else if (c != a) {
    str = "No";
  }
  cout << str << endl;
}