#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, t; cin >> s >> t;
  bool flg = true;
  for(int i = 0; i < t.size(); i++) s.push_back(s[i]);
  for(int i = 0; i < t.size(); i++) {
    if(s[i] != t[0]) continue;
    for(int j = 0; j < t.size(); j++) {
      if(s[i + j] != t[j]) {
        flg = false; break;
      }
    }
    if(flg) break;
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}