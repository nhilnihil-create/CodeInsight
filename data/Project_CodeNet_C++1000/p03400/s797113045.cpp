#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,D,X;
  cin >> N;
  cin >> D >> X;
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  int cnt = X;
  for (int i=0; i<N; i++) {
    int C = D-1;
    cnt++;
    while (C>=A[i]) {
      C = C - A[i];
      cnt++;
    }
  }
  cout << cnt << endl;
  
}