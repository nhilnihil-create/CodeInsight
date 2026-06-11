#include <bits/stdc++.h>
using namespace std;

int main () {
  int N, M, c, d;
  c = 0;
  cin >> N;
  vector<string> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  cin >> M;
  vector<string> b(M);
  for (int i = 0; i < M; i++) {
    cin >> b.at(i);
  }
  for (int i = 0; i < N; i++) {
    d = 0;
    for (int j = 0; j < N; j++) {
      if (a.at(i) == a.at(j)) {
        d++;
      }
    }
    for (int j = 0; j < M; j++) {
      if (a.at(i) == b.at(j)) {
        d--;
      }
    }
    if (d > c) {
      c = d;
    }
  }
  cout << c << endl;
}