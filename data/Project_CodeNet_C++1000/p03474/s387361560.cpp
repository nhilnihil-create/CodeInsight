#include <bits/stdc++.h>
using namespace std;

int main() {  
  int a,b;
  string s;

  cin >> a >> b;
  cin >> s;

  int n = s.size();

  for (int i = 0; i < n; i++) {
    if(i == a) {
      if (s[i] != '-') {
        cout << "No" << endl;
        return 0;
      }
    }
    else {
      if (s[i]!='0' && s[i]!='1' && s[i]!='2' && s[i]!='3' && s[i]!='4' && s[i]!='5' && s[i]!='6' && s[i]!='7' && s[i]!='8' && s[i]!='9') {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}