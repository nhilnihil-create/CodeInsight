#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  bool res = false;
  for (int i = 0; i <= S.size(); ++i) {
    string zen = S.substr(0, i), kou = S.substr(i);
    string wa = kou + zen;
    if (wa == T) res = true;
  }
  if (res) puts("Yes");
  else puts("No");
}