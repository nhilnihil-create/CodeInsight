#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n,m;
  cin >> n >> m;

  int answer = 1;
  for (int i = 1; i * i <= m; i++) {
    if(m % i == 0) {
      int d1 = i;
      int d2 = m/i;
      if(n <= m/d1) answer = max(answer, d1);
      if(n <= m/d2) answer = max(answer, d2);
    }
  }
  cout << answer << endl;

  return 0;
}