#include <bits/stdc++.h>
using namespace std;
#define ll long long 



int main() {
  
  ll N;
  cin >> N;
  
  vector<pair<pair<ll, ll>, ll>> height;
  // 観測データ作成
  
  for (ll i = 0; i < N; i++) {
    ll x, y, h;
    cin >> x >> y >> h;
    
    pair<ll,ll> p = {x, y};
    pair<pair<ll,ll>, ll> q = {p,h};
    
    height.push_back(q);
  }
  
  
  ll M = height.size();
  
  // 中心が (i,j)だったとして
  ll H;
  for (ll i = 0; i <= 100; i++) {
    for (ll j = 0; j <= 100; j++) {
      
      // 0より大きい高さを持っている
        for (ll k = 0; k < M; k++) {
          if (height[k].second > 0) {
            H = height[k].second + abs(height[k].first.first - i) 
              + abs(height[k].first.second - j);
            break;
          }
        
        }
      
      
      bool cond = true;
      // 条件の確認
      for (ll k = 0; k < M; k++) {
        pair<pair<ll,ll>, ll> p1 = height[k];
        
        ll x1 = p1.first.first, y1 = p1.first.second;
        
        if (p1.second != max(H-abs(i-x1)-abs(j-y1), (ll)0)) {
          cond = false;
          break;
        }
      }
      
      if (cond) {
        cout << i << " " << j << " " << H << endl;
        return 0;
      }
    
    }
  }

}