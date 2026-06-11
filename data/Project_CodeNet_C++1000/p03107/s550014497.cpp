#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;

  int zero = 0, one = 0;
  rep(i, S.size()) {
    if (S[i] == '0') {
      zero++;
    } else {
      one++;
    }
  }

  cout << 2 * min(zero, one) << endl;

  return 0;
}
