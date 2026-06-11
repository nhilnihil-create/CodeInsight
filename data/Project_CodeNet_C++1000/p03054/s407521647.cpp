#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X, i) ((X>>i)&1)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define r_all(a) (a).rbegin(), (a).rend()
#define in(x) cin>>x
#define ina(x, n) rep(x_i,n) cin>>x[x_i]
#define outa(x, n) rep(x_i,n) cout<<x[x_i]<<" \n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = (1<<30);
const ll INFL = (1L<<62);

int main() {
  int H, W, n; cin >> H >> W >> n;
  int y, x; cin >> y >> x;
  string s, t; cin >> s >> t;
  bool ok = true;
  int l, r, u, d;
  l = r = x; u = d = y;
  rep(i,n) {
    if (s[i] == 'L') l--;
    if (s[i] == 'R') r++;
    if (s[i] == 'U') u--;
    if (s[i] == 'D') d++;
    if (l == 0 || r == W+1 || u == 0 || d == H+1) {
      ok = false;
      // cout << i+1 << endl;
      // printf("%d, %d, %d, %d\n", l, r, u, d);
      break;
    }
    if (t[i] == 'R' && l != W) l++;
    if (t[i] == 'L' && r != 1)   r--; 
    if (t[i] == 'D' && u != H) u++;
    if (t[i] == 'U' && d != 1)   d--;
  }
  cout << (ok?"YES":"NO") << endl;
  return 0;
}
