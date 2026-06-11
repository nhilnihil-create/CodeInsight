#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, T, B ;
  cin >> A >> T >>B;
  
  if (A*T <= B) {
    cout << A*T <<endl;
  }
  else {
    cout << B <<endl;
  }
}