#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ac=false;
  if(s.at(0)==65){
    ac=true;
    bool Cdeta=false;
    for(int i=1;i<s.size();i++){
      if(s.at(i)<97){
        if(i>1&&i<s.size()-1&&s.at(i)==67&&!Cdeta){
          Cdeta=true;
        }else{
          ac=false;
        }
      }
    }
    ac=ac&Cdeta;
  }
  cout << (ac?"AC":"WA") << endl;
  return 0;
}