#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

void fc(vector<ll> &po, ll n){
  ll power = 1;
  rep(i, po.size()){
    power <<= 1;
    ll now = n;
    po.at(i) = now/power * (power/2);
    now %= power;
    cerr << now << endl;
    now++;
    now -= power/2;
    if(now > 0) po.at(i) += now;
  }
}

int main(){
  ll a, b;
  cin >> a >> b;
  a--;
  vector<ll> po_a(45, 0), po_b(45, 0);
  fc(po_a, a);
  fc(po_b, b);
  ll ans = 0;
  ll add = 1;
  rep(i, po_b.size()){
    ll now = po_b.at(i) - po_a.at(i);
    cerr << po_b.at(i) << " " << po_a.at(i) << endl;
    if(now % 2 == 1) ans += add;
    add <<= 1;
  }
  cout << ans << endl;
  return 0;
}