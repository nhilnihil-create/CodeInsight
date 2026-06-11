#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

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

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m);
    rep(i, m){
        cin >> a.at(i) >> b.at(i);
        --a.at(i), --b.at(i);
    }

    struct UnionFind UF(n);
    ll cur = n*(n-1)/2;
    vector<ll> res;

    for(int i=0; i<m; i++){
        res.push_back(cur);

        int A = a.at(m-1-i), B = b.at(m-1-i);
        if(UF.issame(A, B)) continue;

        ll sa = UF.size(A), sb = UF.size(B);
        dump(sa);
        dump(sb);
        cur -= sa * sb;
        UF.merge(A, B); 

    }

    reverse(res.begin(), res.end());
    rep(i, res.size()){
        cout << res.at(i) << endl;
    }


    return 0;
}
