#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  
  bool can = true;
  int a = min(s.size(), t.size());
  for(int i=0; i<a; i++) {
    if(s[i]>t[i]) {
      can = false;
      break;
    }
    else if(s[i]<t[i]) break;
    else if(i==a-1) {
      if(s.size()>=t.size()) {
        can = false;
        break;
      }
    }
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}