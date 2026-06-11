#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  reverse(A.begin(), A.end());
  int tmp = A.at(0);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    int idx = N-1-i;
    if (idx < A.at(i)) {
      cout << -1 << endl;
      return 0;
    }
    if (tmp - 1 > A.at(i)) {
      cout << -1 << endl;
      return 0;
    }
    if (A.at(i) == tmp) {
      ans += tmp;
    }
    else if (A.at(i) == tmp - 1) {
      tmp = A.at(i);
    }
    else {
      ans += A.at(i);
      tmp = A.at(i);
    }
  }
  if (tmp != 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}