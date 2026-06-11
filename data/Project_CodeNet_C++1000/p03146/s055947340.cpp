#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t s;
  cin >> s;
  vector<int64_t> a(1000000);
  a.at(0) = s;
  int c = 0;
  if (s == 1 || s == 2 || s == 4) {
    cout << 4 << endl;
  }
  else {
  for (int i = 1; i < 1000001; i++) {
    if (a.at(i - 1) % 2 == 0) {
      a.at(i) = a.at(i - 1) / 2;
    }
    else {
      a.at(i) = a.at(i - 1) * 3 + 1;
    }
    if (a.at(i) == 4) {
      c++;
    }
    if (c == 2) {
      cout << i + 1 << endl;
      break;
    }
  }
  }
}