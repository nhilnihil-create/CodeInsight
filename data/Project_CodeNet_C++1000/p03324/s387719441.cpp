#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;
  int d=1;
  for (int i=0; i<D; i++) {
    d*=100;
  }
  if (N==100) {N++;}
  cout << (int)N*d << endl;
}
