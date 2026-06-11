#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  int A;
  int B;
  
  cin >> N;
  cin >> A;
  cin >> B;
  
  if ( N * A > B ) {
    cout << B << endl;
  }
  
  if ( N * A == B ) {
    cout << B << endl;
  }
  
  if ( N * A < B ) {
    cout << N * A << endl;
  }
}
