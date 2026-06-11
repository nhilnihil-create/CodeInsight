#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S, T; cin >> S >> T;
  int L = S.size();
  for (int i = 0; i < L; ++i) {
    bool ok = true;
    for (int j = 0; j < L; ++j) {
      if (S[j] != T[(i + j) % L]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
