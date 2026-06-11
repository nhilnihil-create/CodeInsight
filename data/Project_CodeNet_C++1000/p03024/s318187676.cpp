#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,c=0;
  string S;
  cin >> S;
  r=15-S.size();
  for(int i=0; i<S.size(); i++){
    if(S[i]=='o') c++;
  }
  if(c+r>=8){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}