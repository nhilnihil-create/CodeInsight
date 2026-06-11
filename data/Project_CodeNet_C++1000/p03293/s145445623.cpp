#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S >> T;
  bool a=false;
  for(int i=0;i<S.size();i++){
    if(S==T){
      a=true;
      break;
    }
    char A=T.at(0);
    string U=T.substr(1,S.size()-1);
    T=U+A;
  }
  if(a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}   