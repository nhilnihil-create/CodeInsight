#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>a
#define pb push_back
#define sz(x) int(x.size())

#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll keta(ll n){
  string s = to_string(n);
  ll num = s.size();
  return num;
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w){}
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;

class UnionFind{
  public:
  vi Parent;
  UnionFind(int n){
    Parent = vi(n,-1);
  }

  int root(int a){
    if(Parent[a] < 0) return a;
    else return Parent[a] = root(Parent[a]);
  }

  int size(int a){
    return -Parent[root(a)];
  }

  bool merge(int a, int b){
    a = root(a);
    b = root(b);
    if(a == b) return false;

    if(size(a) < size(b)) swap(a,b);
    Parent[a] += Parent[b];
    Parent[b] = a;

    return true;
  }
};

class Factrial{
  public:
  vl Fac;
  Factrial(int MAX){
    Fac = vl(MAX+1);
    rep(i,MAX) {
      if(i == 0) Fac[i+1] = 1;
      else Fac[i+1] = ((i+1)*Fac[i])%MOD;
    }
  }
};

int main(){
  int n; cin >> n;
  vvi G(n);
  vi deg(n);
  rep(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    G[a].pb(b); G[b].pb(a);
    deg[a]++; deg[b]++;
  }
  vi c(n);
  rep(i, n) cin >> c[i];
  sort(all(c),greater<int>());
  ll M = 0;
  rep(i,n-1) M += c[i+1];

  vi d(n,-1);

  queue<int> q;
  q.push(0);
  int i = 0;

  while(!q.empty()){
    int v = q.front(); q.pop();
    d[v] = c[i];
    i++;
    for(auto nv : G[v]) {
      if(d[nv] != -1) continue;
      q.push(nv);
    }
  }

  cout << M << endl;
  rep(i,n){
    if(i == n-1) cout << d[i] << endl;
    else cout << d[i] << " ";
  }
}