#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int a,b,c,k;
  cin >> a >> b >> c >> k;

  int odd = (b - a);
  int even = (a - b);

  if(k % 2 == 0) cout << even << '\n';
  else cout << odd << '\n';
}
