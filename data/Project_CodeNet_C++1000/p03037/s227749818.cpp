#include <bits/stdc++.h>
using namespace std;
bool in_range(int a, int b, int x) {
  if(a <= x && x <= b) {
    return 1;
  }
  else {
    return 0;
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  int L_max = 1;
  int R_min = N;
  for(int i = 0; i < M; i++) {
    int L, R;
    cin >> L >> R;
    if(L > L_max) {
      L_max = L;
    }
    if(R < R_min) {
      R_min = R;
    }
  }
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    if(in_range(L_max, R_min, i)) {
      ans++;
    }
  }
  cout << ans << endl;
}