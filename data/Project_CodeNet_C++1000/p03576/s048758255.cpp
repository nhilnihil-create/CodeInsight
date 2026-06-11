#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n, k;
  cin >> n >> k;
  ll x[n], y[n], sx[n], sy[n];
  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
    sx[i] = x[i];
    sy[i] = y[i];
  }
  sort(sx, sx+n);
  sort(sy, sy+n);
  ll ans = (sx[n-1] - sx[0]) * (sy[n-1] - sy[0]);
  for(int xi=0; xi<n; xi++){
    for(int xis=xi+1; xis<n; xis++){
      for(int yi=0; yi<n; yi++){
        for(int yis=yi+1; yis<n; yis++){
          ll minx = sx[xi], maxx = sx[xis];
          ll miny = sy[yi], maxy = sy[yis];
          int cnt = 0;
          for(int j=0; j<n; j++){
            if(minx<=x[j]&&x[j]<=maxx&&miny<=y[j]&&y[j]<=maxy) cnt++;
          }
          if(cnt >= k) ans = min(ans, (maxx-minx)*(maxy-miny));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
