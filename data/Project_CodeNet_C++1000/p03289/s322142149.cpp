#include <iostream>
#include <string>

using namespace std;

int main() {
  int c = 0;
  string s; cin >> s;
  if(s[0] != 'A') {
    cout << "WA" << endl;
    return 0;
  }
  if(isupper(s[1]) || isupper(s[s.size() - 1])) {
    cout << "WA" << endl;
    return 0;
  }
  for(int i = 2; i < s.size() - 1; i++) {
    if(s[i] == 'C') c++;
    else if(isupper(s[i])) {
      c = 0; break;
    }
  }
  if(c == 1) cout << "AC" << endl;
  else cout << "WA" << endl;
  
  return 0;
}