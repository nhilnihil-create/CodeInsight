#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  
  bool pc = true;
  for(int i=0; i<s.size(); i++) {
    if(i!=a && !isdigit(s[i])) pc = false;
    if(i==a && s[i]!='-') pc = false;
  }
  if(pc) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}