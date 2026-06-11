#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;

  string T="keyence";
  for(int i=0;i<=7;i++){
    if(S.substr(0,i)==T.substr(0,i) && S.substr(S.size()-7+i,7-i)==T.substr(i,7-i)){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

  return 0;
}