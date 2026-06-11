#include <bits/stdc++.h>
using namespace std;

int main() {

  int X, Y;
  cin >> X >> Y;
  
  if(X == Y) cout << -1 << endl;
  else {    
    for(long long i = 1; i <= Y; i++) {
      
      if((X*i) % Y != 0) {
        cout << X*i << endl;
        break;
      }
      
      if(i == Y) cout << -1 << endl;
      
    }
  }
  
}