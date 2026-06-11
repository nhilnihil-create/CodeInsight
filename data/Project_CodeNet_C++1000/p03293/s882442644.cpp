#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  
  string x = s;
  string y;
  bool Rotation = false;
  for(int i=0; i<s.size(); i++) {
    y = x;
    x.pop_back();
    x = y[s.size()-1]+x;
    if(x == t) Rotation = true; 
  }
  if(Rotation) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}