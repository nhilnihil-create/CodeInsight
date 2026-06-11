#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  if(S.size()==2){
    cout << S << endl;
    return 0;
  }
  for(int i=S.size()-1; i>=0; i--){
    cout << S[i];
  }
  cout << endl;
  return 0;
}