#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll H, W, D; cin >> H >> W >> D;
  ll mx[H*W+1], my[H*W+1];
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      ll a; cin >> a; mx[a] = i; my[a] = j;
    }
  }
  ll mp[H*W+1];
  for (ll i = H*W; i >= 1; i--) {
    if (i+D > H*W) {mp[i] = 0;}
    else {
      mp[i] = mp[i+D] + abs(mx[i]-mx[i+D]) + abs(my[i]-my[i+D]);
    }
  }
  ll Q; cin >> Q;
  for (ll i = 0; i < Q; i++) {
    ll l, r; cin >> l >> r;
    cout << mp[l] - mp[r] << endl;
  }
}   