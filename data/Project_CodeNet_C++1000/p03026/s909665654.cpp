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

vector<vl> g;
vl c, ans;
ll in = 0;

void dfs(ll i, ll p) {
  for(auto v : g[i])
    if(v != p) dfs(v, i);
  ans[i] = c[in];
  in++;
}

int main() {
  ll n;
  cin >> n;
  g.resize(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  c.resize(n);
  rep(i, n) cin >> c[i];
  sort(all(c));
  ans.resize(n);
  dfs(0, -1);
  cout << accumulate(c.begin(), c.end() - 1, 0LL) << endl;
  rep(i, n) cout << ans[i] << ' ';
  cout << endl;
}