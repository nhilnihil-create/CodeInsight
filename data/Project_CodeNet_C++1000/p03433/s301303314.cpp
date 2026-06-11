#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  int A;
  
  cin >> N;
  cin >> A;
  
  if ( N % 500 <= A ) {
    cout << "Yes" << endl;
  }
  
  else if ( N % 500 > A ) {
    cout << "No" << endl;
  }
}
  
  
    
    