#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  
  int N = S.size();
  vector<char> VS(110), VT(220);
  
  for (int i = 0; i < N; i++) {
    VS[i] = S[i];
    VT[i] = T[i];
    VT[N+i] = T[i];
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (VT[i+j] != S[j]) break;
        
      if (j == N-1) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  
  cout << "No" << endl;
  return 0;
  
  

    
   
    
}