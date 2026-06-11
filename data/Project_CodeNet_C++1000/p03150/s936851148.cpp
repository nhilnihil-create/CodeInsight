#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int L=S.size();
  string T="keyence";
  int A=0;
  for(int i=1; i<=7; i++){
    if(S.substr(0, i)==T.substr(0, i)){
      A=i;
    }
  }
  if(A==7){
    cout << "YES" << endl;
  }
  else{
    if(S.substr(L-7+A, 7-A)==T.substr(A, 7-A)){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}