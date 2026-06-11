#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N;
  vector<string> blue(N);
  for (int i = 0; i < N; i++) {
    cin >> blue.at(i);
  }
  cin >> M;
  vector<string> red(M);
  for (int i = 0; i < M; i++) {
    cin >> red.at(i);
  }
  int ans = 0;
  int nb, nr;
  string b;
  bool is_first;
  for (int i = 0; i < N; i++) {
    b = blue.at(i);
    nb = 0;
    nr = 0;
    is_first = true;
    for (int j = 0; j < N; j++) {
      if (b == blue.at(j)) {
        if (j < i) {
          is_first = false;
          break;
        }
        nb++;
      }
    }
    if (!is_first) {
      continue;
    }
    for (int j = 0; j < M; j++) {
      if (b == red.at(j)) {
        nr ++;
      }
    }
    ans = max({ans, nb-nr});
  }
  cout << ans << endl;
}