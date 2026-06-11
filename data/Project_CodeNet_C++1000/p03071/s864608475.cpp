#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int count = 0;
  
  if (A == B) {
    cout << A + B << endl;
  } else if (A > B) {
    cout << A + (A - 1) << endl;
  } else if (B > A) {
    cout << B + (B - 1) << endl;
  }
}