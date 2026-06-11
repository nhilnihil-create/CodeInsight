#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;

  if (p / 1000 == p % 1000 / 100 && p % 1000 / 100 == p % 1000 % 100 /10 ) {
  cout << "Yes" << endl;
  }
  else if ( p % 1000 / 100 == p % 1000 % 100 / 10  && p % 1000 % 100 / 10 == p % 1000 % 100 % 10 / 1) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }    
}  
