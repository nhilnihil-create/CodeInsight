#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int x = 1;
  
  for (int i = 0; i < N; i++) {
    if (x >= K) {
      x += K;
      continue;
    }
    x *= 2;
  }
  
  cout << x << endl;
}