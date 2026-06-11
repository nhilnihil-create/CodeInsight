#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M=0, S=0, p;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> p;
    S+=p;
    M=max(M, p);
  }
  cout << S-M/2 << endl;
}

