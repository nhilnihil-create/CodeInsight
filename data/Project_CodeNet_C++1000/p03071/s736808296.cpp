#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  if (A > B) {
    cout << A + max( A-1 , B ) << endl; 
  }
  else {
    cout << B + max( A , B-1 ) << endl; 
  }
}
