#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define debug(x) cout << #x << " = " << (x) << endl;
#define SUM(x) accumulate(rng(x),0)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define uni(x) x.erase(unique(rng(x)),x.end())
#define SP << " " <<
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int mod = 1000000007;
const double EPS = 1e-9;
const int INF = 1<<30;
const ll INFLL = 1LL<<60;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main () {
  int n, k;
  cin >> n >> k;
  vvi ds(n);
  rep(i,n) {
    int t, d;
    cin >> t >> d;
    --t;
    ds[t].pb(d);
  }
  vi y0, y1;
  rep(i,n) {
    if (ds[i].size() == 0) continue;
    // 昇順ソート(たぶんvectorのアクセスが一番後ろからできるようにするため)
    sort(ds[i].begin(), ds[i].end());
    // 1つ目(種類が増える)として、一番大きいものを選ぶ->y1
    y1.pb(ds[i].back());
    ds[i].pop_back();
    // 2つ目以降は加えても種類が増えない->y0
    y0.insert(y0.end(), ds[i].begin(), ds[i].end());
  }
  // 降順ソート
  sort(y0.rbegin(), y0.rend());
  sort(y1.rbegin(), y1.rend());

  ll ans = 0;

  // Y: 種類数
  // 初期値として、y0から取れるだけ取ったときの残りを設定
  int Y = max(0, k-int(y0.size()));
  // X: 「おいしさ」の総和
  ll X = 0;
  rep(i,Y) X += y1[i];
  rep(i,k-Y) X += y0[i];
  while (1) {
    ans = max(ans, X+(ll)Y*Y);
    if (Y >= k || Y >= y1.size()) break;
    // 種類が増えるものの中から「おいしさ」が最大のものを加える
    X += y1[Y];
    // 種類が増えないものの中から、「おいしさ」が最小のものを除く
    X -= y0[k-Y-1];
    ++Y;
  }
  cout << ans << endl;
  return 0;
}