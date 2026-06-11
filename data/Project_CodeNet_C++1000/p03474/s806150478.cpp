#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b; cin >> a >> b;
  string str; cin >> str;
  
  string ans = "Yes";
  for(int i = 0; i < str.size(); i++) {
    if(i == a) {
      if(str.at(i) != '-') {
        ans = "No";
        break;
      }
    } else {
      int foo = str.at(i) - '0';
      if(foo < 0 || foo > 9) {
        ans = "No";
        break;
      }
    }   
  }
             
  cout << ans << endl;
  
  return 0;
}
  