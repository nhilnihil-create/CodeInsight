#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  cin >> S >> T;
  if( S.size() < T.size() ){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  bool same = true;
  string ans = "UNRESTORABLE";
  for(int i=0;i<=S.size()-T.size();i++){
//    cout << S.substr(i,T.size()) << endl;
    for(int j=0;j<T.size();j++){
      if( S.at(i+j) != T.at(j) && S.at(i+j) != '?' ){
//        cout << S.substr(i,T.size()) << endl;
        same = false;
      }
    }
    if(same){
      ans = S;
      for(int j=0;j<S.size();j++){
        if(S.at(j) == '?')  ans.at(j) = 'a';
      }
      
      for(int j=0;j<T.size();j++){
//        if(S.at(i+j) == '?')  S.at(i+j) = T.at(j);
        ans.at(i+j) = T.at(j);
      }
      
//      cout << S << endl;
//      return 0;
    }
    same = true;
  }
  cout << ans << endl;
  return 0;    
}