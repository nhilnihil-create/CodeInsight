#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  int x[N];
  int y[M];
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> y[i];
  }

  sort(x, x+N);
  sort(y, y+M);

  string ans = "War";
  for (int z = -99; z <= 100; z++) {
    if(!( X < z )) continue;
    if(!( z <= Y )) continue;
    if(!( x[N-1] < z )) continue;
    if(!( z <= y[0] )) continue;
    ans = "No War";
    break;
  }

  cout << ans << endl;

  return 0;
}