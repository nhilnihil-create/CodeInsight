#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A ;

  N = N % 500;
  if ( A - N > 0 || A - N == 0) {
    cout << " Yes " << endl;
   }
  else if ( A - N < 0 ){
     cout << " No " << endl;
   }
} 