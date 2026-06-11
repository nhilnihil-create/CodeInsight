#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B,K;
  cin >> A >> B >> K;
  int a = A;
  
  if (B - A + 1 < K * 2) {
    for (int i = 0; i < B + 1 - A; i++) {
      cout << a << endl;
      a += 1;
    }
  }

  
  else if (B - A + 1 >= K * 2){
    for (int i = 0; i < K; i++) {
      cout << A << endl;
      A += 1;
    }
    for (int i = 0; i < K; i++) {
      cout << B - K + 1 << endl;
      B += 1;
    }
  }
}
  

 