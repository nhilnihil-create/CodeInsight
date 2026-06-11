#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 1e10;
  for(int i = 0; i <= 100000; ++i){
	  ans = min(ans, 2*c*i + max(0, x-i)*a + max(0, y-i)*b);
  }
  cout << ans << endl;
}
