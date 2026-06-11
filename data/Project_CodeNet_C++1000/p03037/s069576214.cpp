#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int lmax = 0;
  int rmin = 100000;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    lmax = max(lmax, l);
    rmin = min(rmin, r);
  }
  int ans = (rmin - lmax + 1 > 0) ? rmin - lmax + 1 : 0;
  cout << ans << '\n';
}