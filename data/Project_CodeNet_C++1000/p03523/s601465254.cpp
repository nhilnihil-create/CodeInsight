#include <bits/stdc++.h>
using namespace std;
int main(){
  string s, ans = "NO";
  cin >> s;
  int n = s.size();
  if (n < 5 || n > 9) {
    cout << ans << endl;
    return 0;
  }
  s += "aaaaa";
  if (s[0] == 'A' && s[1] == 'K' && s[2] == 'I' && s[3] == 'H') {
    if (s[4] == 'A' && s[5] == 'B') {
      if (s[6] == 'A' && s[7] == 'R') {
        if ((s[8] == 'A' || s[8] == 'a') && s[9] == 'a') ans = "YES";
      }
      if (s[6] == 'R') {
        if ((s[7] == 'A' || s[7] == 'a') && s[8] == 'a') ans = "YES";
      }
    }
    if (s[4] == 'B') {
      if (s[5] == 'A' && s[6] == 'R') {
        if ((s[7] == 'A' || s[7] == 'a') && s[8] == 'a') ans = "YES";
      }
      if (s[5] == 'R') {
        if ((s[6] == 'A' || s[6] == 'a') && s[7] == 'a') ans = "YES";
      }
    }
  }
  if (s[0] == 'K' && s[1] == 'I' && s[2] == 'H') {
    if (s[3] == 'A' && s[4] == 'B') {
      if (s[5] == 'A' && s[6] == 'R') {
        if ((s[7] == 'A' || s[7] == 'a') && s[8] == 'a') ans = "YES";
      }
      if (s[5] == 'R') {
        if ((s[6] == 'A' || s[6] == 'a') && s[7] == 'a') ans = "YES";
      }
    }
    if (s[3] == 'B') {
      if (s[4] == 'A' && s[5] == 'R') {
        if ((s[6] == 'A' || s[6] == 'a') && s[7] == 'a') ans = "YES";
      }
      if (s[4] == 'R') {
        if ((s[5] == 'A' || s[5] == 'a') && s[6] == 'a') ans = "YES";
      }
    }
  }
  
  cout << ans << endl;
}