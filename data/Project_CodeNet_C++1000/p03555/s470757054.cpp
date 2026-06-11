#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


bool check(string C1, string C2) {
  for (int i = 0; i < 3; ++i) {
      if (C1.at(i) != C2.at(2 - i)) return false;
  }
  return true;
}

int main () {
  string C1, C2;
  cin >> C1 >> C2;
  
  if (check(C1, C2)) cout << "YES" << endl;
  else cout << "NO" << endl;
}