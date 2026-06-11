#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    mp[a[i]]++;
  }

  sort(a.begin(),a.end());
  int ans = 0;
  for(int i = n-1; i >= 0; i--){
    if(mp[a[i]] == 0) continue;
    mp[a[i]]--;
    int Max = 2;
    while(Max <= a[i]) Max *= 2;
    auto p = *lower_bound(a.begin(),a.end(),Max - a[i]);
    if(p != Max - a[i] || mp[p] == 0) continue;
    mp[p]--;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
