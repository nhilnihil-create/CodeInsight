#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) { // n: 要素数 SUM_UNITY: 基本的に 0 を入れます
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

    bool issame(int x, int y) { // x と y が同じグループにいるかどうかを判定する
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) { // weight(y) = weight(x) + w となるように x と y をマージする
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) { // x と y とが同じグループにいるとき、weight(y) - weight(x) をリターンする
        return weight(y) - weight(x);
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> l(m), r(m), d(m);
    rep(i,m) cin>>l[i]>>r[i]>>d[i];
    UnionFind<int> uf(n+1);
    int i=0;
    for(i=0;i<m;i++){
        if(uf.issame(l[i], r[i])){
            if(uf.diff(l[i], r[i])!=d[i]){
                cout<<"No"<<endl;
                return 0;
            }
        }
        uf.merge(l[i], r[i], d[i]);
    }
    cout<<"Yes"<<endl;
    return 0;
}