#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,ans="AC";
  bool c=false;
  cin >> s;
  if(s[0]!='A') ans="WA";
  for(long i=1;i<s.size();i++) {
    if(s[i]=='C') {
      if((i==1||i==s.size()-1)||c) ans="WA";
      c=true;
    } else if(s[i]<'a') {
      ans="WA";
    }
  }
  if(!c) ans="WA";
  cout << ans << endl;
}