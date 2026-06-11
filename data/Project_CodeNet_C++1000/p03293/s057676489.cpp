# include <iostream>
using namespace std;

int main() {
  string s, t, ans = "No";
  cin >> s >> t;
  
  for (int i = 0; i < s.size(); ++i) {
    string rotate_s = s.substr(s.size() - i, i) + s.substr(0, s.size() - i);
    if (rotate_s == t) {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
  
  return 0;
}