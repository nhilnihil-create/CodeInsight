#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int ans = 1;
  if(n < 105) ans = 0;
  else{
    if(n >= 135 && n < 165) ans++;
    if(n >= 165 && n < 189) ans += 2;
    if(n >= 189 && n < 195) ans += 3;
    if(n >= 195) ans += 4;
  }
  cout << ans << '\n';
}