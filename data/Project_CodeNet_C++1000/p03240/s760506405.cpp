#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];
  ll H, cx, cy;
  bool flag;
  rep(i, 101){
    rep(j, 101){
      flag = true;
      cx = i, cy = j;
      rep(k, n){
        if (h[k] == 0) continue;
        H = h[k] + abs(x[k]-cx) + abs(y[k]-cy);
        break;
      }
      rep(k, n){
        if (h[k] == 0){
          if (H > abs(x[k]-cx) + abs(y[k]-cy)){
            flag = false;
            break;
          }
        }
        else{
          if (H != h[k] + abs(x[k]-cx) + abs(y[k]-cy)){
            flag = false;
            break;
          }
        }
      }
      if (flag) break;
    }
    if (flag) break;
  }
  cout << cx << ' ' << cy << ' ' << H << endl;
  
  return 0;
}