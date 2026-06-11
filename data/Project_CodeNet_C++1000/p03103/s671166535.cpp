#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
using vi = vector<int>;
using vll = vector<ll>;
const ll INF = 1LL<<60;

int main(){
  int n,m; cin >> n >> m;

  vector<pll> d(n);
  rep(i,n){
    ll a,b; cin >> a >> b;
    d[i] = pll(a,b);
  }
  sort(d.begin(), d.end());

  ll ans = 0;
  for(int i = 0; i < n; i++){
    ll a = d[i].first;
    ll b = d[i].second;
    if(b < m){
      ans += a * b;
      m -= b;
    }else{
      ans += a * m;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
