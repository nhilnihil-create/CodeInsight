#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < 4; i++){
    if(n%10 == 2) ans++;
    n /= 10;
  }
  cout << ans << endl;
  return 0;
}