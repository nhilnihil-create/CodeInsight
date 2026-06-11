#include <bits/stdc++.h>
using namespace std;
int main() {
  uint64_t ans = 3, a = 2, b = 1;
  int N;
  cin >> N;
  if(N == 0) {
    ans = 2;
  }
  if(N == 1) {
    ans = 1;
  }
  if(N > 1) {
    for(int i = 2; i < N; i++) {
      a = b;
      b = ans;
      ans = a + b;
    }
  }
  printf("%ld", ans);
}