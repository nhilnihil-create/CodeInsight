#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const double pi = 3.141592653589793;

// union_find
struct UnionFind {
    vector<ll> par; 
    vector<ll> rank;
    UnionFind(ll N) : par(N), rank(N, 1LL) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) par[i] = i;
    }

    void init(ll N){
        par.resize(N);
        rank.assign(N, 1LL);
        for(ll i = 0; i < N; i++) par[i] = i;
    }
    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); 
        ll ry = root(y); 
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        if (rank[rx] < rank[ry]){
            par[rx]=ry;
        }else{
            par[ry]=rx;
            if(rank[rx]==rank[ry])rank[rx]++;
        }
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};




int main(){
    ll N, M;
    cin>>N>>M;
    vector<ll> P(N);
    rep(i, N){
    cin>>P[i];
    P[i]--;
}
vector<ll> X(M), Y(M);
rep(i, M){
    cin>>X[i]>>Y[i];
    X[i]--; Y[i]--;
}
    UnionFind uf(N);
    rep(i, M){
        uf.unite(X[i], Y[i]);
      	//if(uf.same(X[i], Y[i]))cout<<'!';
    }
    ll Ans=0;
    rep(i, N){
        if(uf.same(i, P[i]))Ans++;
      	//cout<<uf.root(i)/*<<" "<<uf.root(P[i])*/<<endl;
      	//cout<<uf.rank[i]<<endl;
    }
    cout<<Ans<<endl;
}