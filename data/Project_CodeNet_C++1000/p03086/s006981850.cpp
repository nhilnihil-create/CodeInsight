#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    bool flag = true;
    int count = 0;
    
    for (int j = i; j < 10; j++) {
      if (flag) {
        if (s[j]=='A'||s[j]=='C'||s[j]=='G'||s[j]=='T') {
          flag = false;
          count ++;
        }
      }
      else {
        if (s[j]=='A'||s[j]=='C'||s[j]=='G'||s[j]=='T')
          count ++;
        else
          break;
      }
    }
    
    if (count > ans)
      ans = count;
  }
  cout << ans << endl;
}