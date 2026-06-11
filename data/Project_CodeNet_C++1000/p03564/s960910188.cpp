#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,K,M = 1;
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    if(M < K) {
      M *= 2;
    }
    else {
      M += K;
    }
  }
  cout << M << endl;
}
