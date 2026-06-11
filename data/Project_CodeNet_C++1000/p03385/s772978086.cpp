#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool A = false, B = false, C = false;
  for (char c: S) {
    if (c == 'a') A = true;
    else if (c == 'b') B = true;
    else C = true;
  }
  if (A && B && C) cout << "Yes" << endl;
  else cout << "No" << endl;
}