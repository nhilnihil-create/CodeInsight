#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int k = s.size();
  bool flag = 1;
  if (k==1) {
    cout << s << endl;
    return 0;
  }
  for (int i=1; i<k; i++) {
    if (s[i] != '9') {
      flag = false;
    }
  }
  int top = (s[0]-'0');
  if (flag) {
     cout << top + 9 * (k-1) << endl;
  } 
  else {
    cout << top - 1 + 9 * (k-1) << endl;
  }
}