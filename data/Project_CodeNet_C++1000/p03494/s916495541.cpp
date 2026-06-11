#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  int ans = 1 << 30;
  rep(_, N) {
    int A;
    cin >> A;
    int count = 0;
    while (A % 2 == 0) {
      A /= 2;
      count++;
    }
    ans = min(ans, count);
  }
  cout << ans << endl;
  return 0;
}