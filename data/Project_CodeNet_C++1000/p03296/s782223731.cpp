#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  int ans = 0, K = 1;
  for (int i = 1; i < N; i++) {
    if (A.at(i) == A.at(i - 1)) {
      K++;
    }
    else {
      ans += K / 2;
      K = 1;
    }
  }
  ans += K / 2;
  
  cout << ans << endl;
}