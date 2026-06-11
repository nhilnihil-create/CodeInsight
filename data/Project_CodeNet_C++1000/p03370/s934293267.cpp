#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x;
  cin >> n >> x;
  int k = 10000;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    x -= m;
    k = min(k,m);
  }
  int ans = n + x/k;
  cout << ans << endl;
  return 0;
}