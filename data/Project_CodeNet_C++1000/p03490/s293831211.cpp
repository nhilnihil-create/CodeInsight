#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string S;
ll X, Y;
const ll LIMIT = 8000;
bitset<2 * LIMIT + 1> P[2];
ll C, D;
bool First = true;

int main() {
  cin >> S >> X >> Y;
  P[0][LIMIT] = 1;
  P[1][LIMIT] = 1;
  S += 'T';
  for (char c : S) {
    if (c == 'F') {
      ++C;
    } else {
      P[D] = First ? P[D] << C : (P[D] << C) | (P[D] >> C);
      D = 1 - D;
      C = 0;
      First = false;
    }
  }
  cout << (P[0][X + LIMIT] && P[1][Y + LIMIT] ? "Yes" : "No") << endl;
}
