#include<bits/stdc++.h>
using namespace std;

int sum_keta(int n){
  int ans = 0;
  while(n > 0){
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

signed main(){
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(sum_keta(i) >= a && sum_keta(i) <= b) ans += i;
  }
  cout << ans << endl;
}