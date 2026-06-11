#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s1;
  cin >> s1;
  string s2;
  int x;
  string ans;
  for (int bit = 0; bit < 8; bit++){
    s2 = s1;
    x = s2[0]-'0';
    for (int i = 0; i < 3; i++){
      if (bit & (1 << i)){
        x = x+(s2[2*i+1]-'0');
        s2.insert(2*i+1,"+");
      }else{
        x = x-(s2[2*i+1]-'0');
        s2.insert(2*i+1, "-");
      }
    }
    if (x == 7){
      ans = s2 + "=7";
      break;
    }
  }
  cout << ans << endl;
}