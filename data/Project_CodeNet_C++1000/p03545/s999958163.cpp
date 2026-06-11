#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
int main() {
  int A, B, C, D;
  string s;
  cin >> s;
  A = s[0] - '0', B = s[1] - '0', C = s[2] - '0', D = s[3] - '0';
  REP(i, 2) REP(j, 2) REP(k, 2) {
    int num = A;
    if (i == 0)
      num += B;
    else
      num -= B;
    if (j == 0)
      num += C;
    else
      num -= C;
    if (k == 0)
      num += D;
    else
      num -= D;
    if (num == 7) {
      cout << A << (i == 0 ? "+" : "-") << B << (j == 0 ? '+' : '-') << C
           << (k == 0 ? '+' : '-') << D << "=7" << endl;
      return 0;
    }
  }
}