# include <iostream>
# include <map>
using namespace std;

int main() {
  int n; cin >> n;
  map<string, int> cnt_map;
  string ans = "Yes";

  char last_char = '\0';
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    
    if (last_char != '\0' && last_char != s[0]) {
      ans = "No";
      break;
    }
    last_char = s[s.size() - 1];
    
    if (cnt_map[s] != 0) {
      ans = "No";
      break;
    }
    ++cnt_map[s];
  }
  cout << ans << endl;
  
  return 0;
}