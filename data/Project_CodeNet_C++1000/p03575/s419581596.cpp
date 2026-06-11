#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


struct UnionFind
{
    vector<int> par;
    vector<int> s;
    
    UnionFind(int N) : par(N), s(N){
        rep(i, N) par[i] = i;
        rep(i, N) s[i] = 1;
    }
    
    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        par[rx] = ry;
        s[rx] += s[ry];
        s[ry] = s[rx];
    }
    
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    
    int size(int x){
        int rx = root(x);
        return s[rx];
    }
};

int main(){
    int N, M; cin >> N >> M;
    vector<pair<int, int>> edges(M);
    rep(i, M){
        int a, b; cin >> a >> b;
        a--;b--;
        edges[i] = {a, b};
    }
    
    int ans = 0;
    rep(i, M){
        UnionFind tree(N);
        rep(j, M){
            if(i != j)tree.unite(edges[j].first, edges[j].second);
        }
        if(tree.size(0) != N)ans++;
    }
    cout << ans << endl;
}