#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
using P = pair<int, int>;
const int INF = 1LL << 62;

signed main(){

  int n, K; cin >> n >> K;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }

  int ans = INF;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        for(int l = 0; l < n; l++){
          int xmax = max({x[i], x[j], x[k], x[l]});
          int xmin = min({x[i], x[j], x[k], x[l]});
          int ymax = max({y[i], y[j], y[k], y[l]});
          int ymin = min({y[i], y[j], y[k], y[l]});
          int cnt = 0;
          for(int m = 0; m < n; m++){
            cnt += (xmin <= x[m] && x[m] <= xmax && ymin <= y[m] && y[m] <= ymax);
          }
          if(cnt >= K) ans = min(ans, (xmax - xmin) * (ymax - ymin));
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
