#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> x(n), y(n), h(n);
  int cx, cy, H, idx;
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> h[i];
    if(h[i] >= 1){
      cx = x[i];
      cy = y[i];
      //H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
      idx = i;
    }
  }
  
  for(int cy = 0; cy <= 100; cy++){
    for(int cx = 0; cx <= 100; cx++){
      H = h[idx] + abs(x[idx] - cx) + abs(y[idx] - cy);
      bool judge = true;
      for(int i = 0; i < n; i++){
        if(idx == i) continue;
        if(max(H - abs(x[i] - cx) - abs(y[i] - cy), 0LL) != h[i]) judge = false;
      }
      if(judge){
        cout << cx << " " << cy << " " << H << endl;
      }
    }
  }

  return 0;
}