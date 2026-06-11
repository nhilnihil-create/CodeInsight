#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define all(x) (x).begin(),(x).end()
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<int>>;
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    rep(i,V){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};
class UnionFind
{
public:
  int par[100005];
  int depth[100005];
  int nGroup[100005];
 
  UnionFind(int n) {
    init(n);
  }
 
  void init(int n) {
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
    }
  }
 
  int root(int x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }
 
  bool same(int x, int y) {
    return root(x) == root(y);
  }
 
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;
 
    if(depth[x] < depth[y]) {
      par[x] = y;
      nGroup[y] += nGroup[x];
      nGroup[x] = 0;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nGroup[y] = 0;
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};
const ll MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
} 
int main() {

    ////////////////////////////////////////
    /* 入力受け取り */
    ////////////////////////////////////////

    /* 縦と横の長さ */
    ll H, W;
    cin >> H >> W;
    /* 盤面 */
    vector<string> field(H);
    for (int h = 0; h < H; ++h) cin >> field[h];
    vector<vector<int> > dist(H, vector<int>(W, -1)); 
    queue<pair<int, int> > que; 
    rep(i,H){
    rep(j,W){
    if(field[i][j]=='#'){
    que.push(make_pair(i, j));
    dist[i][j]=0;
    }}}
    while (!que.empty()) {
        pair<int, int> current_pos = que.front(); // キューの先頭を見る (C++ ではこれをしても pop しない)
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop(); // キューから pop を忘れずに

        // 隣接頂点を探索
        for (int direction = 0; direction < 4; ++direction) {
            int next_x = x + dx[direction];
            int next_y = y + dy[direction];
            if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue; // 場外アウトならダメ
            if (field[next_x][next_y] == '#') continue; // 壁はダメ

            // まだ見ていない頂点なら push
            if (dist[next_x][next_y] == -1) {
                que.push(make_pair(next_x, next_y));
                dist[next_x][next_y] = dist[x][y] + 1; // (next_x, next_y) の距離も更新
             
            }
        }
    }


    ////////////////////////////////////////
    /* 結果出力 */
    ////////////////////////////////////////    

    //int x = gx, y = gy;
    //while (x != -1 && y != -1) {
        //field[x][y] = 'o'; // 通過したことを示す

        // 前の頂点へ行く
        //int px = prev_x[x][y];
        //int py = prev_y[x][y];
        //x = px, y = py;
    //}
    //for (int h = 0; h < height; ++h) {
        //for (int w = 0; w < width; ++w) {
            //cout << std::setw(3) << field[h][w];
        //}
        ll ca = 0;
        rep(i,H){
    rep(j,W){
       ca = max((ll)dist[i][j],ca);}}
    cout << ca << endl;
    }

