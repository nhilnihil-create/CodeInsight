#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int h[5];
  int ans = 0, m = 10;
  REP(i,5) {
    cin >> h[i];
    int c = h[i] % 10;
    if (c != 0) m = min(m,c);
    ans += (h[i] + 9) / 10 * 10;
  }
  
  if (m != 10) ans = ans + m - 10;  
  
  cout << ans << endl;
  
}