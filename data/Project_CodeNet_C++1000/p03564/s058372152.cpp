#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;
  int x = 1;
  
  rep(cnt, N) {
    if (x < K) {
      x *= 2;
    } else {
      x += K;
    }
  }

  cout << x << endl;
}