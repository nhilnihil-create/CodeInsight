#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
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
  ll n, k;
  cin >> n >> k;
  vector<P> p(n);
  rep(i, n) cin >> p[i].second >> p[i].first;
  sort(all(p), greater<P>());
  set<ll> type;
  priority_queue<ll, vl, greater<ll>> q;
  ll base = 0;
  rep(i, k) {
    if(type.count(p[i].second))
      q.push(p[i].first);
    else
      type.insert(p[i].second);
    base += p[i].first;
  }
  ll ans = base + type.size() * type.size();
  rep2(i, k, n) {
    if(q.empty()) break;
    if(type.count(p[i].second)) continue;
    type.insert(p[i].second);
    base += p[i].first;
    ll mn = q.top();
    q.pop();
    base -= mn;
    ans = max(ans, base + ll(type.size() * type.size()));
  }
  cout << ans << endl;
}