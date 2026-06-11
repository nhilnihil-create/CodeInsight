#include <bits/stdc++.h>

using namespace std;

int main () {
  
  int A, B;
  cin >> A >> B;

  bool ans;

  if (A + B > 16 || A < 1 || A > 8 || B < 1 || B > 8) {
    ans = false;
  } else {
    ans = true;
  }

  if (ans) {
    cout << "Yay!" << endl;
  } else {
    cout << ":(" << endl;
  }

  return 0;
}