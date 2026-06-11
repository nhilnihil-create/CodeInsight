#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

struct UnionFind {
    vector<int> size, parents;
    UnionFind(int n){
        size.resize(n,0);
        parents.resize(n,0);
        for(int i = 0; i < n; i++){
            makeTree(i);
        }
    }
    void makeTree(int x){
        parents[x] = x;
        size[x] = 1;
    }
    bool isSame(int x, int y){return findRoot(x) == findRoot(y);}
    void unite(int x, int y){
        x = findRoot(x);
        y = findRoot(y);
        if(size[x] > size[y]){
            parents[y] = x;
            size[x] += size[y];
        }else{
            parents[x] = y;
            size[y] += size[x];
        }
    }
    int findRoot(int x){
        if(x != parents[x]){
            parents[x] = findRoot(parents[x]);
        }
        return parents[x];
    }
    int treeSize(int x){return size[findRoot(x)];}
};

int main(){
    int n, m; cin >> n >> m;
    vector<int> A(m), B(m);
    rep(i,m){
        cin >> A[i] >> B[i];
        --A[i], --B[i];
    }
    UnionFind uf(n);
    ll cur = (ll)n * (n-1) / 2;
    vector<ll> res;
    rep(i,m){
        res.push_back(cur);
        int a = A[m - 1 - i], b = B[m - 1 - i];
        if(uf.isSame(a,b)) continue;
        cur -= (ll) uf.treeSize(a) * uf.treeSize(b);
        uf.unite(a,b);
    }
    reverse(ALL(res));
    rep(i,m) cout << res[i] << endl;
}