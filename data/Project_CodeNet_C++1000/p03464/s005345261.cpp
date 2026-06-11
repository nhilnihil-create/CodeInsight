#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int k; cin >> k;
  vector<int> a(k);
  for(int i = 0; i < k; i++){
    cin >> a[i];
  }

  auto f = [&](int mid){
    for(int i = 0; i < k; i++){
      mid = (mid / a[i]) * a[i];
    }
    return mid;
  };

  int left = -1,right = (int)1e14;
  while(right - left > 1){
    int mid = (left + right) / 2;

    if(f(mid) >= 2) right = mid;
    else left = mid;
  }
  int ans_l = right;

  auto f2 = [&](int mid){
    for(int i = 0; i < k; i++){
      mid = (mid / a[i]) * a[i];
    }
    return mid > 2;
  };

  left = -1,right = (int)1e14;
  while(right - left > 1){
    int mid = (left + right) / 2;

    if(f2(mid)) right = mid;
    else left = mid;
  }
  int ans_r = right-1;

  if(f(ans_l) != 2){
    cout << -1 << endl;
  }else {
    cout << ans_l << " " << ans_r << endl;
  }

  return 0;
}
