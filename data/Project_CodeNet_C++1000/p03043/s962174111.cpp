#include <bits/stdc++.h>
using namespace std;

int num(int x, int y) {
  int cnt = 0;
  while(x<y) {
    cnt++;
    x *= 2;
  }
  return cnt;
}

int main() {
  int k;
  double n;
  cin >> n >> k;
  
  double ans = 0;
  for(int i=1; i<=n; i++) {
    ans += 1/n*pow(0.5, num(i,k));
  }
  
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}