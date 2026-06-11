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
  string s;
  cin >> s;
  ll n = s.size();
  bool ok = true;
  if(s[0] != '1' || s[n - 1] != '0') ok = false;
  rep(i, n / 2) if(s[i] != s[n - 2 - i]) ok = false;
  if(!ok) {
    cout << -1 << endl;
    return 0;
  }
  rep2(i, n / 2 + 1, n) s[i] = '0';
  reverse(all(s));
  vector<vl> g(n);
  ll u = 0, v = 0;
  rep2(i, 1, n) {
    v++;
    g[u].push_back(v);
    if(s[i] == '1') u = v;
  }
  set<P> st;
  rep(i, n) for(auto v : g[i])
      st.insert({min(i + 1, v + 1), max(i + 1, v + 1)});
  for(auto p : st) cout << p.first << ' ' << p.second << '\n';
  return 0;
}