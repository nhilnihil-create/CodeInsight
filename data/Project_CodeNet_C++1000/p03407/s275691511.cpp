#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A=0, B=0, C=0;
  
  cin >> A >> B >> C;
  
  int sum = A+B;
  
  if(sum<C) {
    
    cout << "No" << endl;
    
  } else if(C<=sum) {
    
    cout << "Yes" << endl;
    
  }
  
  return 0;
  
}