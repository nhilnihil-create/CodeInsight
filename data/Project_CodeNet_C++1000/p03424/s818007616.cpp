#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  string C = "";
  
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> S;
    
    if (S=="Y") {
      C = "Four";
      break;
    }
  }
  
  if (C=="") {
    C="Three";
  }
  
  cout << C << endl;
}