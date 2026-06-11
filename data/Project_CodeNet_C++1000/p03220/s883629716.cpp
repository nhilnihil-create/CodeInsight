#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,t,a;
  cin >> n >> t >> a;
  int x,y,j=100000000,ans;
  for(int i=1; i<=n; i++) {
    cin >> x;
	int y = (t*1000-x*6)-a*1000;
    y = abs(y);
	if(j > y) {
      j = y;
      ans = i;
    }
  }
  cout << ans << endl;
}
