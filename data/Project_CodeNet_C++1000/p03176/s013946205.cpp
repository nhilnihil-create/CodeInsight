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

const int N = 1 << 18;
int h[N], a[N], n;

ll t[2*N];
void update(int idx, ll val, int i=1, int s=0, int e=N) {
  const int l = idx, r = idx+1;
  if (r <= s || e <= l) return;
  if (s+1 == e) {
    t[i] = val;
    return;
  }
  int mid = (s+e)/2;
  update(idx, val, i*2, s, mid);
  update(idx, val, i*2+1, mid, e);
  t[i] = max(t[i*2], t[i*2+1]);
}

ll query(int l, int r, int i=1, int s=0, int e=N) {
  if (r <= s || e <= l) return 0;
  if (l <= s && e <= r) return t[i];
  int mid = (s+e)/2;
  return max(query(l, r, i*2, s, mid), query(l, r, i*2+1, mid, e));
}

int main() { // Emily <3
  atexit([](){ cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout << fixed << setprecision(12);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    const int hi = h[i], ai = a[i];
    ll mx = query(0, hi) + (ll)ai;
    ans = max(ans, mx);
    update(hi, mx);
  }
  cout << ans << nl;

  return 0;
}

