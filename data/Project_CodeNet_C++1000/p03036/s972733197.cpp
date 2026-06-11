#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,D,X;
  cin >> R >> D >> X;
  int A = X;
  for (int i = 0; i < 10; i++) {
    cout << R*A - D << endl;
    A = R*A - D;
  }
}