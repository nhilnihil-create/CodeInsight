#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(obj) obj.begin(), obj.end()
#define db(x) cerr << #x << ":" << x << " "
#define dbl(x) cerr << #x << ":" << x << "\n"
#define dbv(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define dbgvv(vv) cerr << #vv << ":\n"; for (auto vec : vv) { for (auto e : vec) cerr << e << " "; cerr << endl; }
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

ll INF = 1000000000000; // 10^12

ll mindis(ll x, ll sw, ll se, ll tw, ll te) {
  ll res = INF;
  auto d = [](ll a, ll b) { return abs(b - a); };
  auto ds = [&](ll x, ll a, ll b) {
    return d(x, a) + d(a, b);
  };
  res = min(res, ds(x, sw, tw));
  res = min(res, ds(x, sw, te));
  res = min(res, ds(x, se, tw));
  res = min(res, ds(x, se, te));
  res = min(res, ds(x, tw, sw));
  res = min(res, ds(x, tw, se));
  res = min(res, ds(x, te, sw));
  res = min(res, ds(x, te, se));
  return res;
}

int main () {
  int A, B, Q; cin >> A >> B >> Q;
  vector<ll> s(A + 2), t(B + 2);
  s.at(0) = t.at(0) = -INF;
  rep2(i, 1, A + 1) cin >> s.at(i);
  rep2(i, 1, B + 1) cin >> t.at(i);
  s.at(A + 1) = t.at(B + 1) = INF;
  // dbv(s); dbv(t);
  rep(i, Q) {
    ll x; cin >> x;
    auto its = lower_bound(all(s), x);
    ll sw = *prev(its), se = *its;
    auto itt = lower_bound(all(t), x);
    ll tw = *prev(itt), te = *itt;
    // db(x); db(sw); db(se); db(tw); dbl(te);
    cout << mindis(x, sw, se, tw, te) << endl;
  }
}