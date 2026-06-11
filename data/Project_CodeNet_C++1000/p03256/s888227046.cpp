#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RREP(i, n) for(int i=(int)(n);i>=0;--i)
#define RFOR(i, a, b) for(int i=(int)(a);i>=(int)(b);--i)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;

const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}

template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, m; cin >> n >> m;
  string s; cin >> s;
  vvi g(n);
  REP(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<bool> ok(n, true);
  set<int> st;
  REP(i, n) {
    st.insert(i);
  }
  bool upd = true;
  while(upd) {
    upd = false;
    set<int> nxtst;
    set<int> diff;
    for(auto &i: st) {
      if(!ok[i]) continue;
      bool a = false, b = false;
      REP(j, SZ(g[i])) {
        int to = g[i][j];
        if(ok[to]) {
          a |= s[to] == 'A';
          b |= s[to] == 'B';
        }
      }
      if(!a || !b) {
        diff.insert(i);
        ok[i] = false;
        upd = true;
      }
    }
    for(auto &e: diff) {
      REP(j, SZ(g[e])) {
        int to = g[e][j];
        if(ok[to]) nxtst.insert(to);
      }
    }
    st = nxtst;
  }

  bool ans = false;
  REP(i, n) {
    ans |= ok[i];
  }
  cout << (ans ? "Yes" : "No") << endl;
}






















