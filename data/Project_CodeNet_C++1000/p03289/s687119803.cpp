#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  if (S[0] != 'A') {
    cout << "WA" << endl;
    return 0;
  }
  
  int C_num = 0;
  int N = S.size();
  for (int i = 2; i < N-1; i++) {
    if (S[i] - 'A' == 2) {
      C_num++;
    }
  }
  
  if (C_num != 1) {
    cout << "WA" << endl;
    return 0;
  }
  

  
  for (int i = 1; i < N; i++) {
    if (S[1] == 'C') {
      cout << "WA" << endl;
      return 0;
    }
    
    if (S[i] != 'C' && S[i] - 'A' <= 25) {
      cout << "WA" << endl;
      return 0;
    }
     
  }
  if (S[N-1] - 'A' <= 25) {
    cout << "WA" << endl;
    return 0;
  }
  
  cout << "AC" << endl;
  
}