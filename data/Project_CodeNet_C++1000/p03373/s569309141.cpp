#include <bits/stdc++.h>
using namespace std;

int choice(int A, int B, int X, int Y) {
  if (X > Y) return A;
  if (X < Y) return B;
}

int main() {
  int A, B, C, X, Y, M, m, aorb, s;
  cin >> A >> B >> C >> X >> Y;
  M = max(X, Y);
  m = min(X, Y);
  aorb = choice(A, B, X, Y);
  s = 0;
  if (A + B <= 2 * C) s = A * X + B * Y;
  else s = min(2 * C * M, 2 * C * m + (M - m) * aorb);
  
  cout << s << endl;
}
