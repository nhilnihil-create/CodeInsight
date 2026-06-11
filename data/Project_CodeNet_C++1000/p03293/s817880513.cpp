#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string st, tt; cin >> st >> tt;
  int n = st.length();
  vector<char> s(n);
  vector<char> t(n);
  for (int i=0; i<n; i++) {
    s[i] = st[i];
    t[i] = tt[i];
  }
  
  bool flag = false;
  for (int i=0; i<n; i++) {
    if (s == t) {
      flag = true; break;
    }
    s.push_back(s[0]); s.erase(s.begin());
  }
  
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}