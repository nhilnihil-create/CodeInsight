#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  string T;
  T=S;
  if(S=="keyence"){
    cout << "YES" << endl;
    return 0;
  }
  for(int i=0;i<S.size();i++){
    for(int j=1;j<=S.size()-i;j++){
      S.erase(S.begin()+i,S.begin()+i+j);
      if(S=="keyence"){
        cout << "YES" << endl;
        return 0;
      }else{
        S=T;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
