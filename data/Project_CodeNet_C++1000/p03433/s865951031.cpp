#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;
  
  if (n < 500) {
    
    if (n > a) {
      
      cout << "No" << endl;
      return 0;
      
    }
    
    cout << "Yes" << endl;
    return 0;
  }
  
  if( (n % 500) > a) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
