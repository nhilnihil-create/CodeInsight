#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;

  int C = 100;
  int SC = 0;
  int A;
  
  for (int i = 0; i < N; i++) {
    SC = 0;
    cin >> A;
    while (A % 2 == 0) {
      SC++;
      A /= 2;
    }
    if (SC < C) {
    C = SC;
    }
  }   
  
  cout << C << endl;   

}