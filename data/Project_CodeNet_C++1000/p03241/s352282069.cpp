#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  set<int> div;
  for (int i = 1; i * i <= M; i++) {
    if (M % i == 0) {
      div.insert(i);
      div.insert(M/i);
    }
  }
  for (auto e :div) {
    if (e >= N) {
      cout << M/e << endl;
      return 0;
    }
  }
}