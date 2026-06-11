#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans = 0, foo;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> foo;
    ans += foo;
  }
  cout << ans - N;
  return 0;
}