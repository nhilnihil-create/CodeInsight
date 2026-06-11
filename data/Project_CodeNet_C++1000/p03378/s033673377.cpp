#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> A(M);
  for (int i = 0; i < M; i++) cin >> A[i];

  int un = 0, up = 0;
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < A.size(); j++) {
      if (A[j] == i) un++;
    }  
  }
  for (int i = X; i < N + 1; i++) {
    for (int j = 0; j < A.size(); j++) {
      if (A[j] == i) up++;
    }      
  }
  cout << min(un, up) << endl;
}