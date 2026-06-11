#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  
  vector<pair<ll, ll>> x(n);
  for(int i = 0; i < n; i++) cin >> x.at(i).first >> x.at(i).second;
  
  sort(x.begin(), x.end());
  
  ll ans = 4e18 + 1;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(j - i + 1 < k) continue;
      
      vector<ll> y;
      for(int l = i; l <= j; l++) y.push_back(x.at(l).second);
      
      sort(y.begin(), y.end());
      
      for(int l = 0; l <= j - i + 1 - k; l++){
        ans = min(ans, (x.at(j).first - x.at(i).first) * (y.at(l + k - 1) - y.at(l)));
      }
    }
  }
  
  cout << ans << '\n';
}