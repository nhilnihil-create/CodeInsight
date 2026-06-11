#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  string ans = "";
  for (int i = 0; i < S.size() - 8; i++) {
    ans += S[i];
  }

  cout << ans << endl;
}