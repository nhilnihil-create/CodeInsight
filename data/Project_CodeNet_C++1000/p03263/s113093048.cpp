#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <deque>
#include <map>
#include<functional>

#define INF 1000000000
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;
using P = pair<long, long>;


const int MAX = 1000000;
const int MOD = 1000000007;


long long fac[MAX], finv[MAX], inv[MAX];

//テーブルの前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        //そのまま計算すると負の値になるのでMODを足す
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//二分累乗法
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

/*
//UnionFind木
struct UnionFind{
   vector<long long int> par; //par[i] : iの親の番号
   vector<long long int> rnk; //root[i] : iの木のサイズ

   //コンストラクタ
   UnionFind(long long int n): par(n), rnk(n){
       //木の初期化
       for(long long int i = 0; i < n; i++){
           par[i] = i;
           rnk[i] = 1;
       }
   }

   //データxが属する木の根を再帰で取得
   long long int root(long long int x){
       if(par[x] == x){
           return x;
       }else{
           return par[x] = root(par[x]);
       }
   }

   //xとyが同じ木に属しているかを判定
   bool same(long long int x, long long int y){
       return root(x) == root(y);
   }

   //xとyの木を併合
   void unite(long long int x, long long int y){
       long long int rx = root(x); //xの根
       long long int ry = root(y); //yの根
       if(rx == ry) return; //根が同じならそのまま

       //併合するときにサイズを足し合わせる
       if(rnk[rx] < rnk[ry]){
           par[rx] = ry;
           rnk[ry] += rnk[rx];
       }else{
           par[ry] = rx;
           rnk[rx] += rnk[ry];
       }
   }

   //属している木のサイズを取得
   long long int size(long long int x){
       return rnk[root(x)];
   }
};
*/

/*
//重み付きUnionFind
template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};
*/

/*
//ダイクストラ
typedef struct edge{
   int to;
   int cost;
} edge;

vector<edge> graph[2010];
long long int d[2010];

void dijkstra(int s){
   priority_queue<P, vector<P>, greater<P> > que;
   for(int i = 0; i < 2010; i++){
       d[i] = INF;
   }
   d[s] = 0;
   que.push(P(s, 0));

   while (!que.empty()) {
       P p = que.top();
       que.pop();
       int v = p.first;
       if (d[v] < p.second) continue;

       for (int i=0; i<graph[v].size(); ++i) {
           edge e = graph[v][i];
           if (d[e.to] > d[v] + e.cost) {
               d[e.to] = d[v] + e.cost;
               que.push(P(e.to, d[e.to]));
           }
       }
   }
}
*/

/*
//素因数分解
map<long long, long long> prime_factor(long long n) {
  map<long long, long long> ret;
  for(long long i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}
*/

int main(){
    int h, w;
    cin >> h >> w;

    int data[h][w];
    int i, j;
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            cin >> data[i][j];
        }
    }

    vector<pair<P, P>> v;
    i = 0;
    j = 0;
    int cnt = 0;
    while(cnt != h*w-1){
        cnt++;
        if(i%2 == 0){
            if(j == w-1){
                if(data[i][j]%2 == 1){
                    v.push_back({{i, j}, {i+1, j}});
                    data[i][j] -= 1;
                    i += 1;
                    data[i][j] += 1;
                }else{
                    i += 1;
                }
            }else{
                if(data[i][j]%2 == 1){
                    v.push_back({{i, j}, {i, j+1}});
                    data[i][j] -= 1;
                    j += 1;
                    data[i][j] += 1;
                }else{
                    j += 1;
                }
            }
        }else{
            if(j == 0){
                if(data[i][j]%2 == 1){
                    v.push_back({{i, j}, {i+1, j}});
                    data[i][j] -= 1;
                    i += 1;
                    data[i][j] += 1;
                }else{
                    i += 1;
                }
            }else{
                if(data[i][j]%2 == 1){
                    v.push_back({{i, j}, {i, j-1}});
                    data[i][j] -= 1;
                    j -= 1;
                    data[i][j] += 1;
                }else{
                    j -= 1;
                }
            }
        }
    }

    cout << v.size() << endl;
    for(i = 0; i < v.size(); i++){
        cout << v[i].first.first+1 << " " << v[i].first.second+1 << " " << v[i].second.first+1 << " " << v[i].second.second+1 << endl;
    }
}