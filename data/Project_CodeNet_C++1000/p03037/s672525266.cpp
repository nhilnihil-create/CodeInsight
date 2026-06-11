#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  
  int min = 0;
  int max = n;
  
  for(int i = 0; i < m; i++) {
  	int l,r; cin >> l >> r;
    if(min < l) min = l;
    if(max > r) max = r;
  }
  int ans = max - min + 1;
  if(max < min) ans = 0;
  cout << ans << endl;

  return 0;
}
