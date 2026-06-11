#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, l, r, i, count = 0;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++) cin >> h.at(i);
  vector<int> ch(N, 0);
  l = 0;
  while (l != N) {
    for (i = 0; i < N; i++)
      if (h.at(i) != ch.at(i)) break;
    if (i == N) break;
    for (; l < N; l++)
      if (h.at(l) != ch.at(l)) break;
    for (r = l; r < N - 1; r++)
      if (h.at(r + 1) == ch.at(r + 1)) break;

    for (i = l; i <= r; i++) ch.at(i) += 1;
    count++;
  }
  cout << count << endl;
  return 0;
}