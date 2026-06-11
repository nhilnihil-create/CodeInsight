#include <bits/stdc++.h>
using namespace std;

int main() {
string s;
  cin>>s;
  for(int i=0;i<8;i++) {
    int x = s[0]-'0';
    string ans = "";
    ans += s[0];
    for(int j=0;j<3;j++){
      if (i>>j&1) {
        x += s[j+1]-'0';
        ans += '+';
      } else {
        x -= s[j+1]-'0';
        ans += '-';
      }
      ans += s[j+1];
    }
    if (x == 7) {
      ans += "=7";
      cout<<ans<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}

