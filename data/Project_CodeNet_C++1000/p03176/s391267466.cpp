#include <bits/stdc++.h>

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define dump_1(x1) cerr << #x1 << ": " << x1 << endl
#define dump_2(x1, x2) \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define dump_3(x1, x2, x3)                                                \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << endl
#define dump_4(x1, x2, x3, x4)                                            \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << ", " #x4 << ": " << x4 << endl
#define dump_5(x1, x2, x3, x4, x5)                                        \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#define dump(...) \
  CHOOSE((__VA_ARGS__, dump_5, dump_4, dump_3, dump_2, dump_1, ~))(__VA_ARGS__)
#define check(s) cerr << s << endl

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using namespace std;

using ll = long long;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

const ll LINF = 2e18;
const int INF = 1e9;

struct SegmentTree {
 private:
  int n;
  vector<ll> node;

 public:
  SegmentTree(vector<ll> v) {
    int sz = v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, INF);

    for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      node[i] = min(node[2 * i + 1], node[2 * i + 2]);
  }

  void update(int x, ll val) {
    x += (n - 1);

    node[x] = val;
    while (x > 0) {
      x = (x - 1) / 2;
      node[x] = max(node[2 * x + 1], node[2 * x + 2]);
    }
  }

  ll getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return node[k];

    ll vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};

int N;
std::vector<ll> h;
std::vector<ll> a;

vector<ll> dp;
SegmentTree *st;

ll getmax(ll l, ll r) { return st->getmax(l, r); }

void setvalue(ll i, ll v) {
  dp.at(i) = v;
  st->update(i, v);
}

void solve() {
  dp.resize(N + 1, 0);
  st = new SegmentTree(dp);

  rep(i, N) {
    ll tmp = getmax(0, h.at(i));
    setvalue(h.at(i), tmp + a.at(i));
  }

  cout << getmax(0, N + 1) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  scanf("%lld", &N);
  h.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &h[i]);
  }
  a.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve();
  return 0;
}
