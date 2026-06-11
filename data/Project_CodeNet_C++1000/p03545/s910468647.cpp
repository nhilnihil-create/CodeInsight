#include <bits/stdc++.h>

#define ll long long
#define REP(i, n) for(ll i = 0; i < (n); ++i)

using namespace std;

int main() {
  int ticket;
  cin >> ticket;
  int A, B, C, D;
  A = ticket / 1000;
  B = (ticket % 1000) / 100;
  C = (ticket % 100) / 10;
  D = ticket % 10;
  for (int flags = (1 << 3) - 1; flags >= 0; --flags) {
    vector<int> sign(3, 1);
    for (int i = 0; i < 3; ++i) sign[i] = flags & (1 << i) ? 1 : -1;
    if(A + sign[0] * B + sign[1] * C + sign[2] * D == 7) {
      vector<char> signChar(3, '+');
      for (int i = 0; i < 3; ++i) signChar[i] = flags & (1 << i) ? '+' : '-';
      cout << A << signChar[0] << B << signChar[1] << C << signChar[2] << D << "=7" << endl;
      return 0;
    }
  }
  return 0;
}
