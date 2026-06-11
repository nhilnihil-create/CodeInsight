#include <bits/stdc++.h>
using namespace std;

int main () {
  int N, b, c, d, e, j;
  d = 0, e = 0;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  for (int i = 0; i < N; i++) {
    b = 0, c = 0;
    for (j = 0; j < N; j++) {
      if (b < a.at(j)) {
        b = a.at(j);
        c = j;
      }
    }
    if (i % 2 == 0) {
      d += b;
    }
    else if (i % 2 == 1) {
      e += b;
    }
    a.at(c) = -1;
  }
  cout << d - e << endl;
}