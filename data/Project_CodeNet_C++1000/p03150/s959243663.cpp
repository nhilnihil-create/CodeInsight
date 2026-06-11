#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,key="keyence";
  cin >> s;
  int st=0,skp=s.size()-7;
  bool isky=false;
  for(int i=0;i<s.size();i++){
    string n="";
    for(int k=0;k<s.size();k++){
      if(k<st||k>=st+skp)
        n+=s.at(k);
      //cout << n << endl;
    }
    if(n=="keyence")
      isky=true;
    st++;
  }
  cout << (isky?"YES":"NO") << endl;
  return 0;
}