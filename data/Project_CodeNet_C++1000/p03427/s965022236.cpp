#include <bits/stdc++.h>
using namespace std;
//解説AC
int main() {
  string s;
  cin>>s;
  if(s.size()==1){
    cout<<s<<endl;
    return 0;
  }
  int kotae=s[0]-'0';
  bool hantei=false;
  for(int i=1;i<s.size();i++){
    if(s[i]=='9')hantei=true;
    else {
      hantei=false;
      break;
    }
  }
  kotae+=9*(s.size()-1);
  if(hantei==false)kotae--;
  cout<<kotae<<endl;
  return 0;
}
  
