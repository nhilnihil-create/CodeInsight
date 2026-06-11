#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  int L, R, L_max = 1, R_min = N;
  for (int i=0; i<M; i++) {
    cin >> L >> R;
    L_max = max(L_max, L), R_min = min(R_min, R);
  }
  cout << max(0,R_min - L_max + 1) << endl;
}
