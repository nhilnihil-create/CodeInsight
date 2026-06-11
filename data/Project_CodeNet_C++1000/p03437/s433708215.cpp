#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long x, y;
  cin >> x >> y;
  if(x%y == 0){
    cout << -1 << endl;
    return 0;
  }
  long long ans = x;
  while(ans%y == 0){
    ans += x;
  }
  cout << ans << endl;  
  return 0;
}