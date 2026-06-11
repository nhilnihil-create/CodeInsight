#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  char c[4] = {'A', 'G', 'C', 'T'};
  int ans = 0, tmp = 0;
  for(int i = 0; i < s.size(); i++) {
    bool match = false;
    for(int j = 0; j < 4; j++) {
      if(s[i] == c[j]) match = true;
    }
    if(match) tmp++;
    else {
      ans = max(ans, tmp);
      tmp = 0;
    }
  }
  ans = max(ans, tmp);
  cout << ans << endl;
  return 0;
}
