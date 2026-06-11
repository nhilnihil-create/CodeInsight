#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,m; cin >> n >> m;
  vector<P> p(n);
  rep(i,n) cin >> p[i].first >> p[i].second; 
  
  sort(p.begin(), p.end());
  ll cost = 0; ll res = m;
  rep(i,n){
    ll a = p[i].first; ll b = p[i].second;
    if(b < res){
      cost += a*b;
      res -= b;
    }
    else{
      cost += res*a;
      break;
    }
  }
  
  cout << cost << endl;
}