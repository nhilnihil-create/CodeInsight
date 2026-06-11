#include <iostream>
#include <string>

using namespace std;

int main() {
  string s; cin >> s;
  int cnt_1 = 0, cnt_2 = 0;
  for(int i = 0; i < s.size(); i += 2) if(s[i] != '0') cnt_1++;
  for(int i = 1; i < s.size(); i += 2) if(s[i] != '1') cnt_1++;
  for(int i = 0; i < s.size(); i += 2) if(s[i] != '1') cnt_2++;
  for(int i = 1; i < s.size(); i += 2) if(s[i] != '0') cnt_2++;
  if(cnt_1 < cnt_2) cout << cnt_1 << endl;
  else cout << cnt_2 << endl;
  return 0;
}