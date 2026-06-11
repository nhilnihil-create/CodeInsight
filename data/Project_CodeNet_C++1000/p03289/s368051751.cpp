#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  int len = (int)s.length();
  string ans = "AC";
  int count = 0;
  if(s[0] != 'A'){
    ans = "WA";
  }
  else{
    for(int i = 1; i < len; ++i){
      if(isupper(s[i]) && s[i] != 'C'){
          ans = "WA";
          //cout << ans << '\n';
      }
      if(s[i] == 'C'){
        //cout << i << '\n';
        if(i == 1 || i == len - 1) ans = "WA";
        count++;
      }
    }
  }
  if(count != 1) ans = "WA";
  cout << ans << '\n';
}