#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long


signed main(){

  int n; cin >> n;
  vector<int> d(n);
  for(int i = 0; i < n; i++){
    cin >> d[i];
  }
  sort(d.begin(),d.end());

  vector<int> v(n+1);
  int pre = 0;
  for(int i = 0; i < n; i++){
    if(pre == 0){
      v[i] = d[i];
      pre = 1;
    }
    else {
      v[i] = 24 - d[i];
      pre = 0;
    }
  }
  v[n] = 0;
  sort(v.begin(),v.end());

  int ans = 24;
  for(int i = 1; i < n+1; i++){
    ans = min(ans,v[i] - v[i-1]);
  }
  cout << ans << endl;

  return 0;
}
