#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int E = abs(A - B);
  int F = abs(B - C);
  int G = abs(C - A);
  if (G <= D || (E <= D && F <= D))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
