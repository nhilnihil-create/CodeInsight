#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);
int main() {
  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a), t(b);
  rep(i,a) cin >> s[i];
  rep(i,b) cin >> t[i];
  while (q--) {
    ll x;
    cin >> x;
    ll res = INF;
    int s1 = lower_bound(s.begin(), s.end(), x) - s.begin(), s2 = -1;
    int t1 = lower_bound(t.begin(), t.end(), x) - t.begin(), t2 = -1;
    if (s1 > 0) s2 = s1 - 1;
    if (t1 > 0) t2 = t1 - 1;
    if (s1 < a && t1 < b) res = min(res, s[s1] + t[t1] - 2 * x - min(s[s1] - x, t[t1] - x));
    if (s2 != -1 && t1 < b) {
      res = min(res, min(x - s[s2], t[t1] - x) + t[t1] - s[s2]);
    }
    if (t2 != -1 && s1 < a) {
      res = min(res, min(x - t[t2], s[s1] - x) + s[s1] - t[t2]);
    }
    if (s2 != -1 && t2 != -1) {
      res = min(res, 2 * x - s[s2] - t[t2] - min(x - s[s2], x - t[t2]));
    }
    cout << res << endl;
  }
  return 0;
}