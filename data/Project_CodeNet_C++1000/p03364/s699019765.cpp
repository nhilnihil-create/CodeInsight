#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S.at(i);
  int ans = 0;
  for (int k = 0; k < N; k++) {
    bool ok = true;
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        int x1 = k+j;
        if (x1 >= N) x1 -= N;
        int x2 = k+i;
        if (x2 >= N) x2 -= N;
        if (S.at(i).at(x1) != S.at(j).at(x2)) ok = false;
      }
    }
    if (ok) ans += N;
  }
  cout << ans << endl;
}