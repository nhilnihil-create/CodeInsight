#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; cin >> S;
  int L = S.size();
  int cnt = 15 - L;
  for (int i = 0; i < L; i++) {
    if (S.at(i) == 'o') cnt++;
  }
  if (cnt >= 8) cout << "YES" << endl;
  else cout << "NO" << endl;
}