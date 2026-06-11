#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<int> h(N);
  int M;
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
    M = max(M, h.at(i));
  }
  int ans = 0;
  for (int i = 1; i <= M; i++) {
    int memo = 0;
    for (int j = 0; j < N; j++) {
      if (h.at(j) >= i) {
        memo = 1;
      }
      else {
        ans += memo;
        memo = 0;
      }
    }
    ans += memo;
  }
  cout << ans << endl;
}