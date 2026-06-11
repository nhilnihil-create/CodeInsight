#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  string s;
  cin >> s;

  set<char> q;
  for (int i = 0; i < s.size(); ++i)
    q.insert(s[i]);

  if (s == "zyxwvutsrqponmlkjihgfedcba") {
    cout << -1 << endl;
  }

  if (s.size() == 26) {
    vector<char> past;
    for (int i = 25; i >= 0; --i) {
      int tmp = 1000;
      int tmp_index = 0;
      for (int j = 0; j < past.size(); ++j) {
        if (s[i] < past[j] && past[j] < tmp) {
          tmp = past[j];
        }
      }
      if (tmp != 1000) {
        s[i] = (char)tmp;
        cout << s.substr(0, i + 1) << endl;
        return 0;
      } else {
        past.push_back(s[i]);
      }
    }
  } else {
    for (char c = 'a'; c <= 'z'; ++c) {
      if (q.find(c) == q.end()) {
        s += c;
        cout << s << endl;
        return 0;
      }
    }
  }

  return 0;
}