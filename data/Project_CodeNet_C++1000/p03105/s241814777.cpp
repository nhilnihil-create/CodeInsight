#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  if (A > B) {
    cout << 0 << endl;
  } else if (A <= B && B / A >= C) {
    cout << C << endl;
  } else {
    cout << B / A << endl;
  }
}