#include<bits/stdc++.h>
using namespace std;
int main() {
  int N; cin >> N;
  int sum = 108;
  for(int i = 1; i < N; i++) {
    int a = i, b = N - i, x = 0, y = 0;
    for(; a > 0;) {
      x += a % 10;
      a /= 10;
    }
    for(; b > 0; ) {
      y += b % 10;
      b /= 10;
    }
    sum = min(sum, (x + y));
  }
  cout << sum << endl;
}