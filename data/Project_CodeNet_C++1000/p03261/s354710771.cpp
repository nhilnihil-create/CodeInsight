# include <iostream>
# include <set>
using namespace std;

int main() {
  int n; cin >> n;
  set<string> word_set;
  string ans = "Yes";

  char last_char = '\0';
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    
    if (last_char != '\0' && last_char != s[0]) {
      ans = "No";
      break;
    }
    last_char = s[s.size() - 1];
    word_set.insert(s);
  }
    
  if (word_set.size() != n) ans = "No";
  
  cout << ans << endl;
  
  return 0;
}