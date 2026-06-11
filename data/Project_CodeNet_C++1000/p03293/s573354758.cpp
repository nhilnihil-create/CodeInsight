#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  cin>>S>>T;
  if(S==T){
    cout<<"Yes"<< endl;
    return 0;
  }
  for(int i=0;i<S.size()-1;i++){
    T=T.back()+T.substr(0,S.size()-1);
    if(S==T){
      cout<<"Yes"<< endl;
      return 0;
    }
  }
  cout<<"No"<< endl;
  return 0;
}