# include <iostream>
using namespace std;

int main() {
  string s; cin >> s;
  string ans = "AC";
  int C_cnt = 0;
  
  for (int i = 0; i < s.size(); ++i) {
    if (i == 0 ) {
      if (s[i] != 'A') ans = "WA";
    }
    else if (2 <= i && i <= s.size() - 2) {
      if (s[i] == 'C') ++C_cnt;
    }
    else {
      if (isupper(s[i])) ans = "WA";
    }
  }
  
  if (C_cnt != 1) ans = "WA";
  cout << ans << endl;
   
  return 0;
}
