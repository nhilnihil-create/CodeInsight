#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N;
  B = 30;
  for(int i = 0; i < N; i++) {
    int total = 0;
    cin >> A;
    while(A % 2 == 0) {
      A = A / 2;
      total += 1;
    }
    if(B > total) {
       B = total;
    }
    else {
      continue;
    }
  } 
  cout << B << endl;
}