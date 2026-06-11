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

string mx(string s, string t) {
  if(s.size() > t.size())
    return s;
  else if(s.size() < t.size())
    return t;
  else if(s >= t)
    return s;
  else
    return t;
}

int main() {
  ll n, m;
  cin >> n >> m;
  vl a(m);
  rep(i, m) cin >> a[i];
  vl v = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vs dp(n + 10, "");
  rep(i, n) {
    if(i > 0 && dp[i] == "") continue;
    for(ll k : a) dp[i + v[k]] = mx(dp[i + v[k]], dp[i] + char(k + '0'));
  }
  cout << dp[n] << endl;
}