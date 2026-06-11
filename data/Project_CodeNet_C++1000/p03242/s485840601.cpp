#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string S;
  cin >> S;
  
  for(int i = 0; i < S.size(); i++){
    if(S[i] == '1'){
      cout << '9';
    }else if(S[i] == '9'){
      cout << '1';
    }else{
      cout << S[i];
    }
  }
  cout << endl;
  return 0;
}