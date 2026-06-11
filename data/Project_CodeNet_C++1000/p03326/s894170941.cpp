#include <bits/stdc++.h>
using namespace std; inline void fileio(const char* in, const char* out) { freopen(in, "r", stdin); freopen(out, "w", stdout); } 
#define TD typedef
#define forx(i,n) for(int i = 0; i < (n); ++i)
#define forxr(i,n) for(int i = (n)-1; i >= 0; --i)
TD long long ll; TD long double ld; TD pair<int,int> pii; TD pair<ll,ll> pll; TD vector<int> VI; TD vector<bool> VB; TD vector<ll> VL;
const char nl = '\n'; const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3fll; const ld EPS = 1e-9, PI = acos(-1);
#define ff first
#define ss second
#define all(c) c.begin(),c.end()

const int N = 1005;
ll x[N], y[N], z[N];
int n, m;

struct Comb {
  ll x, y, z;
  Comb(ll a, ll b, ll c): x(a), y(b), z(c) { }
  bool operator<(const Comb& o) const {
    return (x+y+z) < (o.x+o.y+o.z);
  }
};

ll solve(int X, int Y, int Z) {
  vector<Comb> c;
  for (int i = 0; i < n; ++i) {
    c.emplace_back(x[i] * X, y[i] * Y, z[i] * Z);
  }
  sort(c.begin(), c.end());
  ll xx = 0, yy = 0, zz = 0;
  for (int i = 0; i < m; ++i) {
    xx += c[i].x;
    yy += c[i].y;
    zz += c[i].z;
  }
  return abs(xx) + abs(yy) + abs(zz);
}

int main() {
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(12);
  // Emily <3
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> z[i];
  }
  ll ans = 0;
  for (int i = 0; i < (1 << 3); ++i) {
    int X = i & 1 ? 1 : -1;
    int Y = i & 2 ? 1 : -1;
    int Z = i & 4 ? 1 : -1;
    ans = max(ans, solve(X,Y,Z));
  }
  cout << ans << nl;

  return 0;
}

