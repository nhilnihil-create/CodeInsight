#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = 1e9;
  for (int i = 0; i + 2 < S.size(); i++) {
    ans = min(ans, abs(753 - stoi(S.substr(i, 3))));
  }
  cout << ans << "\n";
}