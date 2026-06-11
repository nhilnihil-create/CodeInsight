#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D, X, S=0, p;
  cin >> N >> D >> X;
  S+=N;
  for (int i=0; i<N; i++) {
    cin >> p;
    if (D>p) {
      S+=(D-1)/p;
    }
  }
  cout << S+X << endl;
}
