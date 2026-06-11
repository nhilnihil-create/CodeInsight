#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin>>s;
  int ichi=0;
  int zero=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='0')zero++;
    else ichi++;
  }
  int kotae=2*min(ichi,zero);
  cout<<kotae<<endl;
  return 0;
}
