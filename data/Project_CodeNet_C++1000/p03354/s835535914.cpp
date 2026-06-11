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
    vector<int> p(N);
    rep(i,N) cin >> p[i];
    UnionFind uf(N+1);
    vector<vector<int>> edges(N);
    rep(i,M){
        int x, y; cin >> x >> y;
        uf.unite(x, y);
    }

    int ans = 0;
    rep(i,N){
        if (uf.same(i+1, p[i])) ans++;
    }

    cout << ans << endl;

}