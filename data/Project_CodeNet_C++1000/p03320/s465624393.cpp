#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll S(ll x) {
  ll s = 0;
  while(x) s += x % 10, x /= 10;
  return s;
}

ll fc(ll a, ll b) { return a * S(b) > b * S(a); }

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  ll k; cin >> k;
  ll t = 1;
  vector<ll> ans;
  ll n = 1;
  while(n <= 1e15) {
    ans.emplace_back(n);
    if(ans.size() >= k) break;
    while(t <= 1e15 && fc(n + t, n + t + t)) t *= 10;
    n += t;
  }
  for(int i = 0; i < k; i++) cout << ans[i] << endl;
}

