#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int A = 1;
  int sum = 1;
  for (int i = 0; i < N; i++){
    if (K <= A){
      sum += K;
    }
    else {
      sum += A;
    }
    A *= 2;
  }
  cout << sum << endl;
}