#include <bits/stdc++.h>

using namespace std;

int main () {

  int A, B;
  bool ans;
  cin >> A >> B;

  if (A % 2 == 0 || B % 2 == 0) {
    ans = false;
  } else {
    ans = true;
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}