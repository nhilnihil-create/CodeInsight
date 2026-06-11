#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector V(5, 0L);
  string S;
  while (cin >> S) {
    if (S.at(0) == 'M') V.at(0)++;
    if (S.at(0) == 'A') V.at(1)++;
    if (S.at(0) == 'R') V.at(2)++;
    if (S.at(0) == 'C') V.at(3)++;
    if (S.at(0) == 'H') V.at(4)++;
  }
  long ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        ans += V.at(i) * V.at(j) * V.at(k);
      }
    }
  }
  cout << ans << "\n";
}