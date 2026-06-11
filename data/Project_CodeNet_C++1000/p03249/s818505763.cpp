#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair

vii child(100010);
vi depth(100010);
bitset<100010> used;

int dfs(int now, int par, int dep) {
  int res = 1;
  depth[now] = dep;
  used[now] = true;
  rep (i, child[now].size()) {
    int nex = child[now][i];
    if (nex == par || used[nex]) {
      continue;
    }
    res += dfs(nex, now, dep + 1);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<pll> d(n);
  map<ll, int> mp;
  rep (i, n) {
    cin >> d[i].first;
    d[i].second = i;
    mp[d[i].first] = i;
  }
  sort(all(d));
  reverse(all(d));
  vi p(n);
  vi num(n, 1);
  int root = d.back().second;
  p[root] = -1;
  num[root] = n;
  rep (i, n - 1) {
    int v = d[i].second;
    ll su = d[i].first + 2 * num[v] - n;
    int u;
    try {
      u = mp.at(su);
    }
    catch (...) {
      cout << -1 << endl;
      return 0;
    }
    p[v] = u;
    child[u].push_back(v);
    num[u] += num[v];
  }
  if (dfs(root, -1, 0) != n) {
    cout << -1 << endl;
    return 0;
  }
  ll sr = 0;
  rep (i, n) {
    sr += depth[i];
  }
  if (sr != d.back().first) {
    cout << -1 << endl;
    return 0;
  }
  rep (i, n) {
    if (p[i] == -1) {
      continue;
    }
    cout << i + 1 << " " << p[i] + 1 << endl;
  }
}
  
  
