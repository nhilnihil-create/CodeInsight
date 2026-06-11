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
  ll n, m;
  cin >> n >> m;
  vector<P> p(m);
  rep(i, m) cin >> p[i].second >> p[i].first;
  sort(all(p));
  ll ans = 0, now = 0;
  rep(i, m) {
    if(p[i].second <= now) continue;
    ans++;
    now = p[i].first - 1;
  }
  cout << ans << endl;
}