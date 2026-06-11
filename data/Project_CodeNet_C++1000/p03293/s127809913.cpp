#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string S, T;
  cin >> S >> T;
  
  int N = (int)S.size();
  
  S += S;
  
  for(int i = 0; i < N; ++i){
    
    string U = S.substr(i,N);
    
    if(U == T){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  
  return 0;
}