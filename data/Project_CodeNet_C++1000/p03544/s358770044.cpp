#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  int64_t Luca0 = 2, Luca1 = 1, Luca2;
  if (N == 1) {
    cout << 1 <<endl;
  }
  else {
    for (int i = 0; i < N-1; i++) {
      Luca2 = Luca1 + Luca0; 
      Luca0 = Luca1;
      Luca1 = Luca2;
    }
    cout << Luca2 << endl;
  }
        
}