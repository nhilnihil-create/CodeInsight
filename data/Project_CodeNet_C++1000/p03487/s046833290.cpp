#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  int memo = 1; 
  for (int i = 0; i < N - 1; i++) {
    if (A.at(i) == A.at(i + 1)) {
      memo++;
    }
    else {
      if (memo < A.at(i)) {
        ans += memo;
        memo = 1;
      }
      else {
        ans += abs(A.at(i) - memo);
        memo = 1;
      }
    }
  }
  if (memo < A.at(N - 1)) {
    ans += memo;
  }
  else {
    ans += abs(A.at(N - 1) - memo);
  }
  cout << ans << endl;
}

    