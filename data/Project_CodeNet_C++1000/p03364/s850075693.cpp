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
    return Parent[a] = root(Parent[a]);
  }

  int size(int a){
    a = root(a);
    return -Parent[a];
  }

  bool merge(int a, int b){
    a = root(a);
    b = root(b);
    if(a == b) return false;

    if(a < b) swap(a,b);
    Parent[a] += Parent[b];
    Parent[b] = a;

    return true;
  }

  bool issame(int a, int b){
    return root(a) == root(b);
  }
};

int n;

bool dfs(int v, vvi &G, vi &color,int col = 0){
  color[v] = col;
  rep(nv,n) {
    if(G[v][nv] == 1e9 || v == nv) continue;
    if(color[nv] == -1){
      if(!dfs(nv, G, color, 1-col)) return false;
    }
    else{
      if(color[v] == color[nv]) return false;
    }
  }

  return true;
}

int main(){
  int n; cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  vector<string> s2(n);
  int ans = 0;
  rep(a,n) {
    rep(i,n) rep(j,n) {
      s2[i] = s[(i+a)%n];
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(s2[i][j] != s2[j][i]) ok = false;
      }
    }
    if(ok) ans += n;
  }

  cout << ans << endl;
}