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
#include <map>

#define INF 100000000
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;
using P = pair<int, int>;

const int MAX = 1000000;
const int MOD = 1000000007;

/*
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

int main(){
    int n;
    cin >> n;

    map<int, int> m;

    int prime[n+1];

    int i, j;
    for(i = 0; i <= n; i++){
        prime[i] = 0;
    }
    prime[0] = 0;
    prime[1] = 1;
    for(i = 2; i <= n; i++){
        if(prime[i] == 0){
            for(j = i; j <= n; j += i){
                prime[j] = i;
            }
        }
    }

    for(i = n; i >= 2; i--){
        int tmp = i;
        while(1){
            //cout << prime[tmp] << endl;
            m[prime[tmp]] += 1;
            tmp /= prime[tmp];
            if(tmp == 1) break;
        }
    }

    int data[5];
    for(i = 0; i < 5; i++){
        data[i] = 0;
    }

    for(auto itr = m.begin(); itr != m.end(); itr++){
        if(itr->second >= 74){
            for(i = 0; i < 5; i++) data[i] += 1;
        }else if(itr->second >= 24){
            for(i = 0; i < 4; i++) data[i] += 1;
        }else if(itr->second >= 14){
            for(i = 0; i < 3; i++) data[i] += 1;
        }else if(itr->second >= 4){
            for(i = 0; i < 2; i++) data[i] += 1;
        }else if(itr->second >= 2){
            for(i = 0; i < 1; i++) data[i] += 1;
        }
    }

    //for(i = 0; i < 5; i++) cout << data[i] << endl;

    long long int ans = 0;
    ans += data[4];
    ans += data[3] * (data[0] - 1);
    ans += data[2] * (data[1] - 1);
    ans += data[1] * (data[1] - 1) * (data[0] - 2) / 2;

    cout << ans << endl;

}
