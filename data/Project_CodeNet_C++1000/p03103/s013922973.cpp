#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,m;
  cin >>n >>m;
  vector<pair<ll, ll>> p(n);
  rep(i,n){
    cin >>p[i].first >>p[i].second;
  }
  sort(p.begin(), p.end());
  ll ans = 0;
  for(int i = 0; m>=0; i++){
    if(p[i].second>=m) {
      ans += m*p[i].first;
      break;
    }
    else{
      ans += p[i].first*p[i].second;
      m -= p[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}