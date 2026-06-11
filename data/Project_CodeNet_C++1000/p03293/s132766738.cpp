#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s,t,u;
  cin >> s >> t;
  
  for ( int i = 0; i < s.size(); i++){
    u = s[s.size()-1];
    s.erase(s.end()-1,s.end());
    u += s;
    if ( u == t ){
      cout << "Yes" << endl;
      return 0;
    }else{
      s = u;
    }
  }
  
  cout << "No" << endl;
  
}