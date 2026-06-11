#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A=0, B=0;
  
  cin >> A >> B;
  
  int sum = A+B;
  int sub = B-A;
  
  if(B%A==0) {
    
    cout << sum << endl;
    
  } else {
    
    cout << sub << endl;
    
  }
  
  return 0;
  
}