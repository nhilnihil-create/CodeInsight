#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int N = 0;
  
  for (A; A <= B; A++) {
    if (A / 10000 == A - (A / 10) * 10 && A / 1000 - (A / 10000) * 10 == A / 10 - (A / 100) * 10) {
      N += 1;
    }
  }
  cout << N << endl;
}