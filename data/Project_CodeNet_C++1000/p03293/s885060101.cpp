#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string S, T;
  cin >> S >> T;
  
  int N = (int)S.size();
  
  for(int i = 0; i < N; ++i){
    
    string U;
    U += S.at(N-1);
    S.pop_back();
    U += S;
    
    if(U == T){
      cout << "Yes" << endl;
      return 0;
    }
    
    S = U;
  }
  
  cout << "No" << endl;
  
  return 0;
}
