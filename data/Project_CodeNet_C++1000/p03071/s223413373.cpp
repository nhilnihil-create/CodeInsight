#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  
  if (A >= B+1){
    cout << A*2 - 1 << endl;
  }
  else if (A+1 <= B){
    cout << B*2-1 << endl;
  }
  else {
    cout << A+B << endl;
  }
}