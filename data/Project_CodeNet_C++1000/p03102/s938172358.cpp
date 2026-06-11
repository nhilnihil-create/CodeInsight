#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, C, A, S=0, count=0;
  cin >> N >> M >> C;
  vector<int> B(M);
  for (int i=0; i<M; i++) {
    cin >> B[i];
  }
  for (int i=0; i<N; i++) {
    S=0;
    for (int j=0; j<M; j++) {
      cin >> A;
      S+=A*B[j];
    }
    S+=C;
    if (S>0) {
      count++;
    }
  }
  cout << count << endl;
}

