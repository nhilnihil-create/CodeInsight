#include <bits/stdc++.h>
using namespace std;

// repetition
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

// container util
#define all(x) (x).begin(), (x).end()

// typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

// const value
// const ll MOD = 1e9 + 7;
// const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
// const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

// conversion
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline ll toLL(string s) {
  ll v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, d;
  cin >> h >> w >> d;
  ll b[h][w];
  map<int, PII> mp;
  rep(i, h) rep(j, w) {
    cin >> b[i][j];
    mp[b[i][j]] = PII(i, j);
  }
  ll sum[2 * h * w + 1];
  memset(sum, 0, sizeof(sum));
  rep(i, h * w) {
    auto now = mp[i];
    auto next = mp[i + d];
    sum[i + d] =
        sum[i] + abs(now.first - next.first) + abs(now.second - next.second);
  }
  int q;
  cin >> q;
  rep(_, q) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l] << endl;
  }
  return 0;
}
