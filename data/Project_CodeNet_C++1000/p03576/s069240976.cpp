#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N, K; cin >> N >> K;
  vector < pair<ll, ll> > XY(N);
  for (int i = 0; i < N; i++){
    ll X, Y; cin >> X >> Y;
    XY[i] = make_pair(X, Y);
  }

  ll ans = -1;
    for (int i1 = 0; i1 < N; i1++){
      ll X1 = XY[i1].first, Y1 = XY[i1].second;
      for (int i2 = 0; i2 < N; i2++){
        ll X2 = XY[i2].first, Y2 = XY[i2].second;
        for (int i3 = 0; i3 < N; i3++){
          ll X3 = XY[i3].first, Y3 = XY[i3].second;
          for (int i4 = 0; i4 < N; i4++){
            ll X4 = XY[i4].first, Y4 = XY[i4].second;

            ll X = max(max(X1, X2), max(X3, X4));
            ll x = min(min(X1, X2), min(X3, X4));
            ll Y = max(max(Y1, Y2), max(Y3, Y4));
            ll y = min(min(Y1, Y2), min(Y3, Y4));

            int cnt = 0;
            for (int i = 0; i < N; i++){
              if (x <= XY[i].first && XY[i].first <= X){
                if (y <= XY[i].second && XY[i].second <= Y){
                  cnt++;
                }
              }
            }
            
            if (cnt >= K){
              if (ans == -1) ans = (X - x) * (Y - y);
              else ans = min(ans, (X - x) * (Y - y));
            }
          }
        }
      }
    }
  
  
  
  cout << ans << endl;
  
  return 0;
}