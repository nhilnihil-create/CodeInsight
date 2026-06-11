#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i;
  int cnt = 0;
  bool a=true;
  if(s[0]!='A') a=false;
  for(i=2;i<=s.size()-2;i++) if(s[i]=='C') cnt++;
  if(cnt!=1) a=false;
  for(i=0;i<s.size();i++){
    if(s[i]=='A' || s[i]=='C') continue;
    else if(s[i]<'a' || s[i]>'z') a=false;
  }
  cout << (a? "AC":"WA") << "\n";
  return 0;
}