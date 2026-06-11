#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  if(a > b){
    ans += a;
    ans += max(a - 1, b);
  }
  else{
    ans += b;
    ans += max(a, b - 1);
  }
  cout << ans;
  return 0;
}