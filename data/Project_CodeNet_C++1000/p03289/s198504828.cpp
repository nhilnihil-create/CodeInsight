#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  
  bool ok = true;
  if (s[0] != 'A') ok = false;
  rep(i,26) if (s[1] == 'A' + i || s[n-1] == 'A' + i) ok = false;
  string t = s.substr(2,n-3);
  int cnt = 0;
  rep(i,t.size()) {
    if (t[i] == 'C') cnt++;
    rep(j,26) {
      if (t[i] == 'A' + i && t[i] != 'C') ok = false;
    }
  }
  if (cnt != 1) ok = false;
  
  if (ok)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
}