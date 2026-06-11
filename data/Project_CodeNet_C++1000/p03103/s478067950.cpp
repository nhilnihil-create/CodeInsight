#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;
using P = pair<ll, ll>;

int main(){
  ll n, m;
  cin >> n >> m;
  vector<P> ab(n);
  rep(i, n){
    ll a, b;
    cin >> a >> b;
    ab[i] = P(a, b);
  }
  sort(ab.begin(), ab.end());
  ll num = 0;
  ll ans = 0;
  ll x = 0;
  while(1){
    if (num + ab[x].second >= m){
      ans += ab[x].first * (m - num);
      break;
    }
    else{
      num += ab[x].second;
      ans += ab[x].first * ab[x].second;
      x++;
    }
  }
  cout << ans << endl;
  
  return 0;
}