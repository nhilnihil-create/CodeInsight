#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long n, k;
  long b;
  long cnt = 0;
  
  cin >> n >> k;
  rep(b, n+1) {
    if (b <= k) continue;
    if (k == 0) {
      cnt = n * n;
      break;
    }
    
    cnt += ((n) / b) * (b - k);
    cnt += max((n % b) - k + 1, 0L);
  }
  cout << cnt;
}
