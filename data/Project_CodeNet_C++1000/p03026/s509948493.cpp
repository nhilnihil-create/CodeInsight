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
  int n;
  cin >> n;
  VI a(n - 1), b(n - 1);
  rep(i, n - 1) cin >> a[i] >> b[i];
  VI edge[n];
  ll rmEdge[n] = {0};
  rep(i, n - 1) {
    a[i]--, b[i]--;
    edge[a[i]].push_back(b[i]);
    edge[b[i]].push_back(a[i]);
  }
  VLL c(n);
  rep(i, n) cin >> c[i];
  sort(all(c));
  reverse(all(c));

  ll choose = 0;
  ll m = 0;
  ll ans[n];
  memset(ans, -1, sizeof(ans));
  int cidx = 0;
  // start
  queue<int> que;
  que.push(0);
  ans[0] = c[cidx];
  cidx++;
  while(que.empty() == false) {
    int cc = que.front();
    que.pop();
    for(int x : edge[cc]) {

      if(ans[x] == -1) {
        que.push(x);
        ans[x] = c[cidx];
        m += c[cidx];
        cidx++;
      }
    }
  }
  cout << m << endl;
  rep(i, n) { cout << ans[i] << " "; }
  cout << endl;
  return 0;
}
