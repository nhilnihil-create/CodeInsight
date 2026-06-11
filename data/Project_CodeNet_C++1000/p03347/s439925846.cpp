#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

void fail(){
  cout << -1 << endl;
  exit(0);
}

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  if(a[0] != 0) fail();

  int ans = 0;
  for(int i = 1; i < n; i++){
    if(a[i-1] + 1 < a[i]) fail();
    if(a[i-1] + 1 == a[i]){
      ans++;
    }else{
      ans += a[i];
    }
  }
  cout << ans << endl;

  return 0;
}
