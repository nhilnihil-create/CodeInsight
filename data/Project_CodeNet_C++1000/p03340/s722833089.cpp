#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long ans = 0;
  for (long l = 0, r = 0, now = 0, sum = 0; r < N; r++) {
    now ^= A.at(r), sum += A.at(r);
    while (l <= r && now != sum) {
      now ^= A.at(l), sum -= A.at(l), l++;
    }
    ans += r - l + 1;
  }
  cout << ans << "\n";
}