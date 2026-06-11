#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, T;
  cin >> A >> B >> T;
  
  if (T < A) {
    cout << 0 << endl;
  } else {
    cout << (T / A) * B << endl;
  }
}