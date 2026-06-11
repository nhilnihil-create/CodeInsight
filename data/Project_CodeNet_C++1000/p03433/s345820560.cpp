#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int C = A % 500;
    if ( C <= B ) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
}
