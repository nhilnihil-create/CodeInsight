#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  
  if (B-A <= 200) {
    for (int i = A; i <= B; i++) {
      if (i-A < K || B-i < K)
        cout << i << endl;
    }
  } else {
    for (int i = A; i < A+K; i++) {
      cout << i << endl;
    }
    for (int i = B-K+1; i <= B; i++) {
      cout << i << endl;
    }
    
  }
}