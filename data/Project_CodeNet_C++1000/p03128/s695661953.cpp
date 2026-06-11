#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

string maxs(string s, string t) {
  if(s.size() > t.size()) return s;
  if(s.size() < t.size()) return t;
  if(t > s) return t;
  return s;
}

int main() {
  int n, m;
  cin >> n >> m;
  vi a(m);
  rep(i, m) cin >> a[i];
  vi b = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vs dp(n + 1, "");
  rep(j, n) rep(i, m) {
    if(j != 0 && dp[j] == "") continue;
    int nj = j + b[a[i]];
    if(nj <= n) dp[nj] = maxs(dp[nj], dp[j] + (char)('0' + a[i]));
  }
  cout << dp[n] << endl;
}