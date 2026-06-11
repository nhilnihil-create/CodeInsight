#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X, L=0, R=0, p;
  cin >> N >> M >> X;
  for (int i=0; i<M; i++) {
    cin >> p;
    if (p<X) {
      L++;
    }
    else {
      R++;
    }
  }
  int m=min(L, R);
  cout << m << endl;
  
  
}
