#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  for (int i = 0; i < N; i++) cin >> m[i];
  sort(m.begin(), m.end());
  int sum = 0, cnt = 0;
  for (int i = 0; i < N; i++) {
    sum += m[i];
    cnt++;
  }
  while (sum <= X) {
    sum += m[0];
    cnt++;
  }
  cout << cnt - 1 << endl;
}