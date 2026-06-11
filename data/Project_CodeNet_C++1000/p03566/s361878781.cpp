#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int TT = 0;
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T[i]; TT += T[i];
  }
  int v, x = 0;
  vector<int> MaxV(TT * 2 + 1, INT_MAX - 100);
  for (int i = 0; i < N; i++) {
    cin >> v;
    for (int j = 0; j < T[i]; j++) {
      MaxV[x] = min(MaxV[x], v * 2);
      MaxV[x+1] = min(MaxV[x+1], v * 2);
      MaxV[x+2] = min(MaxV[x+2], v * 2);
      x += 2;
    }
  }
  MaxV.front() = MaxV.back() = 0;
  for (int i = 0; i < TT * 2; i++) MaxV[i+1] = min(MaxV[i]+1, MaxV[i+1]);
  for (int i = TT * 2; 0 < i; i--) MaxV[i-1] = min(MaxV[i]+1, MaxV[i-1]);

  double ans = 0;
  for (int i = 0; i < TT * 2; i++) ans += (MaxV[i] + MaxV[i+1]) / 8.0;
  printf("%.15f\n", ans);
}