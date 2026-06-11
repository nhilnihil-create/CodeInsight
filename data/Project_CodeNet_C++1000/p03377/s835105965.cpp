#include <bits/stdc++.h>

using namespace std;

int main () {
  
  int A, B, X;
  cin >> A >> B >> X;

  bool ans;

  if (X < A || X > A + B) {
    ans = false;
  } else {
    ans = true;
  }

  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}