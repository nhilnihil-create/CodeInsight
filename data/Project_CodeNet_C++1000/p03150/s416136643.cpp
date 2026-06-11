#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  if(s.substr(0,7)=="keyence"||s.substr(s.size()-7,7)=="keyence") { 
    cout << "YES" << endl;
    return 0;
  }  
  for(int i=1; i<=6; i++){
    if(s.substr(0,i)+s.substr(s.size()-(7-i),7-i)=="keyence") {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}