#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  A += B;
  C += D;
  cout << ((A < C) ? "Right" : (A > C) ? "Left" : "Balanced") << "\n";
}