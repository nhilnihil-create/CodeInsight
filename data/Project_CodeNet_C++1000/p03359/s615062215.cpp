#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a=0, b=0;
  
  cin >> a >> b;
  
  if(a==b || a<b) {
    
    cout << a << endl;
    
  } else if(b<a) {
    
    cout << a-1 << endl;
    
  }
  
  return 0;
  
}