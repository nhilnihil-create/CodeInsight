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
  ll x, y;
  cin >> s >> x >> y;
  s.push_back('T');
  vl a, b;
  ll cnt = 0;
  bool t = false;
  rep(i, s.size()) {
    if(s[i] == 'F')
      cnt++;
    else {
      if(t)
        b.push_back(cnt);
      else
        a.push_back(cnt);
      cnt = 0;
      t = !t;
    }
  }
  bool ans = true;
  ll geta = 8010;
  rep(q, 2) {
    ll n = a.size();
    bool dp[n + 1][16020] = {};
    rep(i, n + 1) rep(j, 16020) dp[i][j] = false;
    dp[0][geta] = true;
    rep(i, n) rep(j, 16020) {
      if(!dp[i][j]) continue;
      dp[i + 1][j + a[i]] = true;
      if(q == 1 || i != 0) dp[i + 1][j - a[i]] = true;
    }
    if(!dp[n][x + geta]) ans = false;
    swap(x, y);
    swap(a, b);
  }
  cout << (ans ? "Yes" : "No") << endl;
}