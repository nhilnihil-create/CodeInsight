#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int R=0;
  
  cin >> R;
  
  if(R<1200) {
    
    cout << "ABC" << endl;
    
    return 0;
    
  } else if(1200<=R && R<2800) {
    
    cout << "ARC" << endl;
    
    return 0;
    
  } else if(2800<=R) {
    
    cout << "AGC" << endl;
    
    return 0;
    
  }
  
}