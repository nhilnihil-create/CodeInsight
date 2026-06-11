#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A, H, mi;
  cin >> N >> T >> A;
  double m=10000000;
  for (int i=0; i<N; i++) {
    cin >> H;
    double d=T-H*0.006;
    if (abs(d-A)<m) {
      m=abs(d-A);
      mi=i+1;
    }
  }
  cout << mi << endl;
}

