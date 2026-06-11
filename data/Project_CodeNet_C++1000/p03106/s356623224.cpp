#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int A, B, K, M;
  cin >> A >> B >> K;
  M=min(A,B);
  vector<int> C(M);
  for (int i=0; i<M; i++) {
    if (A%(i+1)==0 && B%(i+1)==0) {
      C[i]=i+1;
    }
    else {
      C[i]=-1;
    }
  }
  sort(C.begin(),C.end());
  reverse(C.begin(),C.end());
  cout << C[K-1] << endl;
}