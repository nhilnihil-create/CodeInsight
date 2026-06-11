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

vector<vl> g;
vl c, ans;
ll i = 0;
vb seen;

void dfs(ll j) {
  for(auto v : g[j]) {
    if(seen[v]) continue;
    seen[v] = true;
    dfs(v);
  }
  ans[j] = c[i];
  i++;
}

int main() {
  ll n;
  cin >> n;
  g = vector<vl>(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  c = vl(n);
  ans = vl(n);
  seen = vb(n, false);
  rep(i, n) cin >> c[i];
  sort(all(c));
  seen[0] = true;
  dfs(0);
  cout << accumulate(all(c), 0) - c[n - 1] << endl;
  rep(i, n) cout << ans[i] << ' ';
  cout << endl;
}