#include<bits/stdc++.h>
using namespace std;
int main() {
  int N; cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];
  int res = 0;
  for (int i = 0; i < N; i++) {
    bool f = true;
    
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        int R = (i + r) % N;
        int C = c;
        int R2 = (c + i) % N;
        int C2 = r;
        f = f && S[R][C] == S[R2][C2];
      }
    }
    res += f;
  }
  cout << res * N << endl;
}