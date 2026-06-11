#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t; cin >> n >> t;
  int x, y;
  int ans = INT_MAX;int idx = -1;
  for(int i = 0; i < n; ++i){
     cin >> x >> y;
    if(y <= t)ans = min(ans,x);
  }
  if(ans < INT_MAX)cout << ans << '\n';
  else cout << "TLE" << '\n';
}