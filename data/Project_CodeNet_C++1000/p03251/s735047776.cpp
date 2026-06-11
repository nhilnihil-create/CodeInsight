#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N);
  for (int i = 0; i < N; i++) cin >> x[i];
  vector<int> y(M);
  for (int i = 0; i < M; i++) cin >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  bool can = false;
  if (x[N-1] < y[0]) {
    for (int i = x[N-1]+1; i <= y[0]; i++) {
      if (i > X && i <= Y) {
        can = true;
        break;
      }
    }
  }
  if (can) cout << "No War" << endl;
  else cout << "War" << endl;
}
