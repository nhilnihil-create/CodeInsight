#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  vector<string> w;
  bool flag = true;
  
  string s; cin >> s;
  w.push_back(s);
  
  for (int i=1; i<n; i++) {
    cin >> s;
    if (find(w.begin(), w.end(), s) != w.end()) {
      flag = false;
      break;
    }
    
    if (w[i-1][w[i-1].length()-1] != s[0]) {
      flag = false;
      break;
    }
    
    w.push_back(s);
  }
  
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}