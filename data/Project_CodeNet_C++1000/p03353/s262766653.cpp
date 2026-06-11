#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int K;
  cin >> s >> K;

  set<string> s_substring;
  for(int i = 0; i < s.size(); i ++) {
    string tmp;
    for(int j = i; j < min((int)s.size(), i + 5); j++) {
      tmp.push_back(s[j]);
      s_substring.insert(tmp);
    }
  }

  set<string>::iterator itr = s_substring.begin();
  advance(itr, K-1);

  cout << *itr << endl;

  return 0;
}