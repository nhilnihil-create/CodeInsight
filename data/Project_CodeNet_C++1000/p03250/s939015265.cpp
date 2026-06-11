#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int mx = max({a, b, c});
  int ans = a + b + c + 9 * mx;
  
  cout << ans << endl;
  return 0;
}