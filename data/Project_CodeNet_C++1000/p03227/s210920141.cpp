#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  string ans;
  if (S.size() == 2) {
    ans = S;
  }
  else {
    ans = S.at(2);
    ans += S.at(1);
    ans += S.at(0);
  }
  cout << ans << endl;
  return 0;
}
