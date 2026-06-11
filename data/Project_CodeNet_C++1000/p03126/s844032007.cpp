#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, K, A;
  cin >> N >> M;
  vector<int> V(M, 0);

  for (int i=0; i<N; i++) {
    cin >> K;
    for (int j=0; j<K; j++) {
      cin >> A;
      V[A-1]++;
    }
  }
  
  int C=0;
  for (int i=0; i<M; i++) {
    if (V[i]==N) {
      C++;
    }
  }
  cout << C << endl;
}

