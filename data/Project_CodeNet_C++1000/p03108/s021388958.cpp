#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};


int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M),B(M);
    rep(i,M){
        cin >> A[i] >> B[i];
    }
    UnionFind uf(N+1);
    vector<ll> ans(M+1);
    ans[M] = N*(N-1)/2;
    for(int i=M-1;i>=0;i--){
        if(uf.issame(A[i],B[i])){
            ans[i]=ans[i+1];
            continue;
        }
        ll size_a = uf.size(A[i]);
        ll size_b = uf.size(B[i]);
        ans[i] = ans[i+1] - size_a * size_b;
        uf.merge(A[i],B[i]);
    }
    rep(i,M){
        cout << ans[i+1] << endl;
    }
    return 0;
}