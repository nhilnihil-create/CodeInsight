#include <bits/stdc++.h>
using namespace std;
int main() {
  string s,t;
  cin >> s >> t;
  char c;
  for(int i=0; i<s.size(); i++) {
    if(s == t) {
      cout << "Yes" << endl;
      return 0;
    }
    string t = s.substr(s.size()-1);
    s.insert(0,t);
    s.pop_back();
  }
  cout << "No" << endl;
}