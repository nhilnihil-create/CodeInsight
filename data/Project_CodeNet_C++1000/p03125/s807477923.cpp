#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  if (A == B) {
    cout << A + B << endl;
  } else if (B % A == 0) {
    cout << A + B << endl;
  } else {
    cout << B - A << endl;
  }
}