#include <bits/stdc++.h>
using namespace std;

int main() {

  string s;
  cin >> s;

  int K;
  cin >> K;

  set<string> st;

  for (int i = 0; i < s.size(); i++) {
    string s_ = "";
    for (int j = i; j < s.size(); j++) {
      s_ += s[j];
      st.insert(s_);
      if (K < s_.size()) {
        break;
      }
    }
  }

  int count = 1;
  for (auto item:st) {
    if (count == K) {
      cout << item << endl;
      break;
    }
    count++;
  }

  return 0;

}
