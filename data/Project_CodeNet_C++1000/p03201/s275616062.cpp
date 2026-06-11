#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  multiset<ll, greater<ll>> st;
  map<ll, ll> mp;
  rep(i, n) {
    ll a;
    cin >> a;
    st.insert(a);
    mp[a]++;
  }
  ll ans = 0;
  for(auto v : st) {
    if(mp[v] == 0) continue;
    ll k = 1;
    while(k <= v) k *= 2;
    if(k - v > v) continue;
    mp[v]--;
    if(mp[k - v] > 0) {
      mp[k - v]--;
      ans++;
    }
  }
  cout << ans << endl;
}