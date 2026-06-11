#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  double T, A;
  cin >> T >> A;
  double mi = 100000000, pmi = -1;
  for (int i = 0; i < N; ++i) {
    double h;
    cin >> h;
    double t = T - h * 0.006;
    if (mi > abs(t - A)) mi = abs(t - A), pmi = i+1;
  }
  cout << pmi << endl;
}