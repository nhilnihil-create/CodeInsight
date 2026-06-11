#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n,a,b;
  cin >> n >> a >> b;
  cout << min(a,b) << " " << max(0, a+b-n) << '\n';
}