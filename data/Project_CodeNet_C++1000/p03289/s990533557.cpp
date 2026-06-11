#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n;
  n = s.size();
  bool can = false;
  bool can1 = false;
  bool can2 = false;
  bool can3 = false;
  if (s.at(0) == 'A') {
    can1 = true;
  }
  int cnt = 0;
  int ci;
  for (int i = 2; i < n - 1; i++) {
    if (s.at(i) == 'C') {
      cnt++;
      ci = i;
    }
  }
  if (cnt == 1) {
    can2 = true;
  }
  bool nonc = true;
  int al;
  for (int i = 1; i < n; i++) {
    if (i == ci) {
      continue;
    }
    al = s.at(i) - 'a';
    if (!(al >= 0 && al <= 25)) {
      nonc = false;
    }
  }
  if (nonc) {
    can3 = true;
  }
  if (can1 && (can2 && can3)) {
    cout << "AC" << endl;
  }
  else {
    cout << "WA" << endl;
  }
}
