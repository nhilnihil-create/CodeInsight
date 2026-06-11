#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
     cin >> A.at(i);
  }
  int prev = -1;
  int ans = 0;
  for (int x: A) {
    if (x == prev) {
      ans += 1;
      prev = -1;
    } else {
      prev = x;
    }
  }
  cout << ans << endl;
}