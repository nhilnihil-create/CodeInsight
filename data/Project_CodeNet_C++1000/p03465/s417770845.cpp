#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }

  bitset<2020 * 2020> dp;
  dp[0] = true;
  for(int i = 0; i < n; i++){
    dp |= dp << a[i];
  }

  for(int i = (sum+1)/2; i < n * 2020; i++){
    if(dp[i]){
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
