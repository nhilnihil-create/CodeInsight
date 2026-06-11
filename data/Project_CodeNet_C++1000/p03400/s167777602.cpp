#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D, X, A;
  cin >> N >> D >> X;
  while (cin >> A) X+=(D+A-1)/A;
  cout << X << "\n";
}