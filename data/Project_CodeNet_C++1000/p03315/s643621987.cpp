#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < 4; i++){
  if (s.substr(i, 1) == "+") ans += 1;
  else if (s.substr(i, 1) == "-") ans -= 1;
  }
  cout << ans << endl;
}