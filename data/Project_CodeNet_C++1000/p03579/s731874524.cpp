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
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<vl> seen(n, vl(2, 0));
  stack<pair<int, int>> st;
  seen[0][0] = 1;
  st.push({0, 0});
  while(!st.empty()) {
    int i = st.top().first;
    int j = st.top().second;
    st.pop();
    for(auto v : g[i]) {
      if(seen[v][!j]) continue;
      seen[v][!j] = true;
      st.push({v, !j});
    }
  }
  ll odd = 0, even = 0;
  rep(i, n) {
    if(seen[i][0] && !seen[i][1]) even++;
    if(!seen[i][0] && seen[i][1]) odd++;
  }
  ll ans = n * (n - 1) / 2 - m - odd * (odd - 1) / 2 - even * (even - 1) / 2;
  cout << ans << endl;
}