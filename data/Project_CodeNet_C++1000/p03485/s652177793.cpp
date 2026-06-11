#include <bits/stdc++.h>
using namespace std;

int main() {

  int a, b;
  cin >> a >> b;
  
  if ( (a + b) / 2 * 2 < a + b) {
    cout << (a + b) / 2 + 1 <<endl;
  }
  else { 
    cout << (a + b) / 2 <<endl;
  }
  
}
