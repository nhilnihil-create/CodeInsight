#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll result;
  if (A + B < C * 2) {
    result = A * X + B * Y;
  } else {
    result = min(C * min(X, Y) * 2 + (max(X, Y) - min(X, Y)) * (max(X, Y) == X ? A : B), C * max(X, Y) * 2);
  }
  cout << result << endl;
}