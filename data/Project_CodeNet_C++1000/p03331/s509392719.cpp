#include <bits/stdc++.h>
using namespace std;
int sum(int x){
  int res = 0;
  while(x > 0){
    res += x%10;
    x /= 10;
  }
  return res;
}
int main(){
  int n, ans = 1e9;
  cin >> n;
  for(int a=1, b=n-1; a<=b; ++a, --b) ans = min(ans, sum(a)+sum(b));
  cout << ans << endl;
}