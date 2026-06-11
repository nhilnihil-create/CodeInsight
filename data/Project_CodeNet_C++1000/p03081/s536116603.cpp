#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<char> t(q), d(q);
  for(int i = 0; i < q; i++){
    cin >> t[i] >> d[i];
  }

  int left = -1, right = n;
  while(right - left > 1){
    int mid = (left + right) / 2;
    int pos = mid;
    for(int i = 0; i < q; i++){
      if(s[pos] == t[i]){
        pos += (d[i] == 'L' ? -1 : 1);
      }
      if(pos == -1 || pos == n) break;
    }
    if(pos == n){
      right = mid;
      continue;
    }
    (pos == -1 ? left : right) = mid;
  }
  int l = right;

  left = -1, right = n;
  while(right - left > 1){
    int mid = (left + right) / 2;
    int pos = mid;
    for(int i = 0; i < q; i++){
      if(s[pos] == t[i]){
        pos += (d[i] == 'L' ? -1 : 1);
      }
      if(pos == -1 || pos == n) break;
    }
    if(pos == -1){
      left = mid;
      continue;
    }
    (pos != n ? left : right) = mid;
  }
  int r = left;
  cout << max(0LL, r - l + 1) << endl;

  return 0;
}
