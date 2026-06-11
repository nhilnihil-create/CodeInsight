#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int ans = 1e9;
  for (int i = 0; i < (int)S.size()-2; i++) {
    int num = stoi(S.substr(i,3));
    ans = min(ans, abs(753-num));
  }

  cout << ans << endl;
  return 0;
}