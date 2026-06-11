#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V(N), C(N);
  for (int i=0; i<N; i++) {
    cin >> V[i];
  }
  for (int i=0; i<N; i++) {
    cin >> C[i];
  }
  
  int M=0;
  int m=0;
  for (int b=0; b<(1<<N); b++) {
    bitset<20> s(b);
    m=0;
    for (int i=0; i<N; i++) {
      if (s.test(i)) {
        m+=(V[i]-C[i]);
      }
    }
    M=max(M, m);
  }
  cout << M << endl;
}
