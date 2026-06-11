#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  string s, t;
  cin >> s >> t;

  map<char, char> s_to_t;
  map<char, char> t_to_s;
  for (int i = 0; i < s.size(); ++i) {
    if (s_to_t.find(s[i]) == s_to_t.end() && t_to_s.find(t[i]) == t_to_s.end()) {
      s_to_t[s[i]] = t[i];
      t_to_s[t[i]] = s[i];
    } else if (!(s_to_t[s[i]] == t[i] && t_to_s[t[i]] == s[i])) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}