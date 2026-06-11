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
  ll n, m;
  cin >> n >> m;
  vector<vl> g(n);
  vl cnt(n, 0);
  rep(i, n + m - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    cnt[b]++;
    g[a].push_back(b);
  }
  queue<ll> q;
  vl d(n, 0), p(n, -1);
  rep(i, n) if(cnt[i] == 0) q.push(i);
  while(!q.empty()) {
    ll i = q.front();
    q.pop();
    for(auto v : g[i]) {
      cnt[v]--;
      if(d[v] < d[i] + 1) {
        d[v] = d[i] + 1;
        p[v] = i;
      }
      if(cnt[v] == 0) q.push(v);
    }
  }
  rep(i, n) cout << p[i] + 1 << '\n';
}