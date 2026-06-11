#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, X, x;
  cin >> A >> B;
  X = A * B;
  x = X % 2;
  if (x == 0) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}
