#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  map<char,char> st,ts;
  int N = s.size();
  for (int i = 0; i < N; i++) {
    if (!st.count(s[i]) && !ts.count(t[i])) {
      st[s[i]] = t[i];
      ts[t[i]] = s[i];
    }
    else if (st[s[i]] != t[i] || ts[t[i]] != s[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}