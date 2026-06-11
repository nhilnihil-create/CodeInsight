#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  int a, ans = 0;
  rep(i,0,N-1) {
    cin >> a;
    ans += a - 1;
  }

  cout << ans << endl;
  return 0;
}
