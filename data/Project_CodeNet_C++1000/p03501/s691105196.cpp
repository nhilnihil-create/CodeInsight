#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int t,A,B;
  cin >> t >> A >> B;
  
  int prA = t * A, prB = B;
  
  if (prA >= prB) {
    cout << prB << endl;
  }
  
  else cout << prA << endl;
  
} 