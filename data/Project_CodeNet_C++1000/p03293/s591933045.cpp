#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.size();
  s = s + s;

  bool flag = false;
  for (int i = 0; i <= n; i++) {
    string tmp = s.substr(i, n);
    if(tmp == t) {
      flag = true;
      break;
    }
  }

  if(flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}