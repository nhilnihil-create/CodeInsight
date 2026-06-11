#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b; cin >> n >> a >> b;
  auto calc = [&](int x){
    int res = 0;
    while(x){
      res += x % 10;
      x /= 10;
    }
    return res;
  };
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int t = calc(i);
    if(t >= a && t <= b)ans += i;
  }
  
  cout << ans << endl;
}