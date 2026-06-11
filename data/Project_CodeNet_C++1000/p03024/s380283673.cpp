#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string S;
  cin >> S;
  int ok = 0, n = S.length();
  for (int i = 0; i < n; i++) {
    ok += S[i] == 'o' ? 1 : 0;
  }
  cout << (ok + (15 - n) >= 8 ? "YES" : "NO") << endl;
  return 0;
}