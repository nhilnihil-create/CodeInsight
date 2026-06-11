#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, X, Y, Z, P;
  cin >> A >> B;
  X = A + B;
  Y = A - B;
  Z = A * B;
  P = max(X, Y);
  cout << max(P, Z) << endl;
}