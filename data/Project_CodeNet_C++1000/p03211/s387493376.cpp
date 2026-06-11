#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,X;
  int res=999;
  cin >> S;
  for(int i=0;i<S.size()-2;i++){
    X = S.substr(i,3);
    res = min(res,abs(stoi(X)-753));
  }
  
  cout << res << endl;
  return 0;
}