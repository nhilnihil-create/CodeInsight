#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, sum, M;
  cin >> N >> X;
  
  vector<int> A(N);    
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  sort(A.begin(),A.end());
  
  sum = 0;
  M = 0; 
  
  
  
  for (int i = 0; i < N; i++) {
    sum = sum + A.at(i);
    M = M + 1;
      
    if ( sum == X ) {
      break;
    }
    else if ( sum > X ) {
      M = M-1;
      break;
    }  
  } 
  
  if (sum < X) {
    M = M-1;
  }
  
  
  cout << M << endl;
    
}