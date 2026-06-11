#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int ans = 1;
  rep(_, N) {
    if (ans * 2 < ans + K) {
      ans *= 2;
    }
    else {
      ans += K;
    }
  }
  cout << ans << endl;
  
  return 0;
}