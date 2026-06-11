#include <bits/stdc++.h>
using namespace std;

int main () {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int den = 0;
  int bus = 0;

  if (A >= B) {
    den = B;
  }
  if (A <= B) {
    den = A;
  }
  if (C >= D) {
    bus = D;
  }
  if (C <= D) {
    bus = C;
  }

  cout << den + bus << endl;
}
