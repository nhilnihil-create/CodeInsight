#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s; cin >> s;
  int n = s.length();
  bool flag = true;
  int cntC = 0;
  
  for (int i=0; i<n; i++) {  
    if (i == 0 && s[i] != 'A') {
      flag = false; break;
    }
    if ((i == 1 || i == n-1) && s[i] >= 'A' && s[i] <= 'Z') {
      flag = false; break;
    }
    if (i >= 2 && i <= n-2) {
      if (s[i] == 'C') cntC++;
      if (s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'C') {
        flag = false; break;
      }
    }
  }

  if (flag && cntC == 1) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
  return 0;
}