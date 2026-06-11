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
  ll n, q;
  string s;
  cin >> n >> q >> s;
  vl sum(n + 1, 0);
  rep2(i, 1, n) {
    sum[i + 1] = sum[i];
    if(s[i - 1] == 'A' && s[i] == 'C') sum[i + 1]++;
  }
  rep(_, q) {
    ll l, r;
    cin >> l >> r;
    l--;
    ll ans = sum[r] - sum[l];
    if(l > 0 && sum[l + 1] > sum[l]) ans--;
    printf("%lld\n", ans);
  }
}