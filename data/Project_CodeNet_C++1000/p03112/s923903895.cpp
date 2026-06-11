#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll inf = 1e15;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll ns, nt, q;
  cin >> ns >> nt >> q;
  set < ll > s, t;
  for(int i = 0; i < ns; i++){
    ll a; cin >> a;
    s.insert(a);
  }
  for(int i = 0; i < nt; i++){
    ll a; cin >> a;
    t.insert(a);
  }

  s.insert(inf);
  s.insert(-inf);
  t.insert(inf);
  t.insert(-inf);

  while(q--){
    ll x; cin >> x;
    auto it = s.lower_bound(x);
    ll sr = *it - x, sl = x - *(--it);
    it = t.lower_bound(x);
    ll tr = *it - x, tl = x - *(--it);

    ll ans = max(sl, tl);
    ans = min(ans, 2 * sl + tr);
    ans = min(ans, sl + 2 * tr);
    ans = min(ans, max(sr, tr));
    ans = min(ans, sr + 2 * tl);
    ans = min(ans, 2 * sr + tl);

    cout << ans << '\n';
  }
}
