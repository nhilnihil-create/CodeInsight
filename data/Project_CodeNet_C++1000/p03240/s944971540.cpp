#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<vector<ll>> vec;
  rep(i,n){
    ll x, y, h;
    cin >> x >> y >> h;
    vector<ll> r = {x,y,h};
    vec.push_back(r);
  }
  for(ll i = 0; i < 101; i++) {
    for(ll j = 0; j < 101; j++) {
      ll h = -1;
      bool ok = true;
      rep(k,n) {
        if (vec[k][2] == 0) continue;
        ll tmp = vec[k][2] + abs(vec[k][0] - i) + abs(vec[k][1] - j);
        if (h == -1) {
          h = tmp;
        } else if (h > 0) {
          if (h != tmp) {
            ok = false;   
          }
        }
      }
      rep(k,n) {
        if (vec[k][2] == 0) {
          ll tmp = abs(vec[k][0] - i) + abs(vec[k][1] - j);
          if (h > tmp) ok = false;
        }
        
      }
      if (ok) {
        cout << i << " " << j << " " << h;
        return 0;
      }
      h = -1;
    }
  }
  return 0;
}