#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

struct union_find{
    vector<int> par;
    vector<int> rank;
    vector<int> siz;
    
    union_find(int N) : par(N), rank(N), siz(N){
        rep(i,N){
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
        }
    }
    
    int root(int x){
        if (par[x] == x){
            return x;
        }
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]){
            par[rx] = ry;
            siz[ry] += siz[rx];
        }
        else{
            par[ry] = rx;
            siz[rx] += siz[ry];
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }
    
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    
    int size(int x){
        return siz[root(x)];
    }
};

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> X(M);
    vector<ll> Y(M);
    vector<ll> Z(M);
    rep(i,M){
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;
        Y[i]--;
    }
    union_find tree(N);
    rep(i,M){
        tree.unite(X[i], Y[i]);
    }
    ll ans = 0;
    rep(i,N){
        if (tree.root(i) == i) ans++;
    }
    cout << ans << endl;
}
