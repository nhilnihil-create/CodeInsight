#include<bits/stdc++.h>
using namespace std;


int main(){
  string s,t;
  cin >> s >> t;
  bool ok=false;
  for(int i=0;i<s.size();++i){
    if(s==t){
      ok=true;
      break;
    }
    s=s[s.size()-1]+s.substr(0,s.size()-1);
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
