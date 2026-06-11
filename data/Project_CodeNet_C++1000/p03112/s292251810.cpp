#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e11;

int main() {
  ll A, B, Q; cin >> A >> B >> Q;
  vector<ll> s;
  s.push_back(-INF);
  for (ll i = 0; i < A; i++) {
    ll a; cin >> a; s.push_back(a);
  }
  s.push_back(INF);
  
  vector<ll> t;
  t.push_back(-INF);
  for (ll i = 0; i < B; i++) {
    ll b; cin >> b; t.push_back(b);
  }
  t.push_back(INF);
  
  for (ll i = 0; i < Q; i++) {
    ll x; cin >> x;
    ll sf = *lower_bound(s.begin(), s.end(), x);
    ll si = *(lower_bound(s.begin(), s.end(), x)-1);
    ll tf = *lower_bound(t.begin(), t.end(), x);
    ll ti = *(lower_bound(t.begin(), t.end(), x)-1);
    
    ll res = max(sf,tf)-x;
    res = min(res, x-min(si,ti));
    res = min(res, 2*sf-ti-x);
    res = min(res, sf+x-2*ti);
    res = min(res, 2*tf-si-x);
    res = min(res, tf+x-2*si);
    cout << res << endl;
  }
}