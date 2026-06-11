#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  map<ll,ll> od,ev;
  for(ll i=0;i<n;i++) {
    if(i%2) ev[a[i]]++;
    else od[a[i]]++;
  }
  pll evx={-1,0};
  pll odx={-1,0};
  for(auto p:ev) {
    if(evx.second<p.second) {
      evx=p;
    }
  }
  for(auto p:od) {
    if(odx.second<p.second) {
      odx=p;
    }
  }
  ll ans=evx.second+odx.second;
  if(evx.first==odx.first) {
    pll evs={-1,0};
    pll ods={-1,0};
    for(auto p:ev) {
      if(evx.first!=p.first&&evs.second<p.second) {
        evs=p;
      }
    }
    for(auto p:od) {
      if(odx.first!=p.first&&ods.second<p.second) {
        ods=p;
      }
    }
    ans=max(evx.second+ods.second,evs.second+odx.second);
  }
  cout << n-ans << endl;
}