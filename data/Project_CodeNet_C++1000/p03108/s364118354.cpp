#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


struct UnionFind {
    vector<int> d; 

    UnionFind(int N=0) : d(N, -1){} 

    int find(int x) { 
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    bool unite(int x, int y) {
        x = find(x); 
        y = find(y); 
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x; 
        return true; 
    }

    bool same(int x, int y) { 
        return find(x) == find(y);
    }

    int size(int x){
        return -d[find(x)];
    }
};


int main(){
    int N, M; cin >> N >> M;
    vector<pair<int, int>> edges;
    rep(i,M){
        int a, b; cin >> a >> b;
        a--;
        b--;
        edges.emplace_back(a, b);
    }
    UnionFind uf(N);
    vector<ll> ans(M+1);
    ans[M-1] = (ll)N*(N-1)/2;
    for (int i = M-1; i >= 1; i--){
        ans[i-1] = ans[i];
        int vertex1 = edges[i].first;
        int vertex2 = edges[i].second;
        if(!uf.same(vertex1, vertex2)){
            ans[i-1] -= uf.size(vertex1) * uf.size(vertex2);
            uf.unite(vertex1, vertex2);
        }
    }

    rep(i,M){
        cout << ans[i] << endl;
    }

}