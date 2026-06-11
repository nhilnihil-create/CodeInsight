#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, fN = 0;
  cin >> N;
  M = N;
  for(int i = 0; i < 8; i++) {
    fN += N % 10;
    N /= 10;
    if (N == 0) {
      break;
    }
  }
  if(M % fN == 0){
    cout << "Yes" << endl;
  }
  else {
      cout << "No" << endl;
  }
}