#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using mat = vector<vector<ll>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


// 二部マッチング：構造体--------------------------------------
// 二部グラフ。容量が全て1である最大流問題に帰着できる。
// がここではsupersourceとsupersinkを追加する必要はない
// verifyはここ <http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp>

struct Bipartite_Matching {
  int V;                 // 頂点数
  vector<vector<int>> G; // グラフの隣接リスト表現
  vector<int> match;     // マッチングのペア
  vector<bool> used;     // DFSで既に調べたかのフラグ

  Bipartite_Matching(int n) : V(n), G(n), match(n, -1), used(n, false) {}

  // uとvを結ぶ辺をグラフに追加する
  void add_edge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }

  // 増加パスをDFSで探す
  bool dfs(int v){
    used[v] = true;
    for (int i=0; i<G[v].size(); i++){
      int u = G[v][i], w = match[u];
      if (w < 0 || !used[w] && dfs(w)){
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }

  // 二部グラフの最大マッチングを求める
  int bipartite_matching() {
    int res = 0;
    match.assign(match.size(), -1);
    for (int v=0; v<V; v++){
      if (match[v] < 0){
        used.assign(used.size(), false);
        if (dfs(v)) res++;
      }
    }
    return res;
  }
};


int main() {
  int N; cin >>N;
  Bipartite_Matching bm(2*N);
  vector<pair<int,int>> red(N); rep(i, N) cin >>red[i].first >>red[i].second;
  rep(j, N){
    int blue = N+j;
    int c,d; cin >>c >>d;
    rep(i, N){
      if (red[i].first < c && red[i].second < d) bm.add_edge(i, blue);
    }
  }
  int res = bm.bipartite_matching();
  cout <<res <<endl;
}
