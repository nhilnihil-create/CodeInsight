#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int max_v = 3*100000;

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

    int N,M; cin >> N >> M;
    vector<pair<int, int>> edges;
    rep(i,M){
        int x, y, z; cin >> x >> y >> z;
        x--;
        y--;
        edges.emplace_back(x,y);
    }

    UnionFind uf(N);    
    rep(i,M){
        uf.unite(edges[i].first, edges[i].second);
    }

    set<int> roots;
    rep(i, N){
        roots.insert(uf.find(i));
    }

    cout << roots.size() << endl;

    

}