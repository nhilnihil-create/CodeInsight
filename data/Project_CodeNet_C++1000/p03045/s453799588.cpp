#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> size;
    UnionFind(int N): par(N),size(N) {

         //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++){
            par[i] = i;
            size[i] = -1;
        }
            
    }
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        size[ry] += size[rx];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int getsize(int x){
        return -size[root(x)];
    }
    int getNunion(){
        map<int,int> m;
        rep(i,par.size()){
            m[this->root(i)]++;
        }
        return int(m.size());
    }
};

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> X(M), Y(M), Z(M);
    UnionFind tree(N);
    rep(i,M){
        cin >> X[i] >> Y[i] >> Z[i];
        //tree.unite(0,1);
        tree.unite(int(--X[i]), int(--Y[i]));
    }
    cout << tree.getNunion() << endl;
}