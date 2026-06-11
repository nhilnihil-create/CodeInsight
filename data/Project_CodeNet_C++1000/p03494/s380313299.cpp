#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 100000;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    int divider = 0;
    while (A % 2 == 0) {
      A /= 2;
      divider++;
    }
    if (divider < ans) {
      ans = divider;
    }
  }
  cout << ans;
}