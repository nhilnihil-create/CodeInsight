#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  cin >> x >> y ;
  
  if ( (x*y)%2 == 0 ) {
    
    cout << "Even" << endl;
  }
  
  else if ( (x*y)%2 == 1 ) {
    
    cout << "Odd" << endl;
  }
}