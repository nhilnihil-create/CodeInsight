#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
     
struct UnionFind {
    vector<int> d ;
    UnionFind (int n = 0) : d(n, -1) {}
    int find(int x){
        if(d[x] < 0) return x ;
        else {
            return find(d[x]) ;
        }
    }
    bool unite(int x, int y){
        x = find(x) ;
        y = find(y) ;
        if(x == y){
            return false ;
        }
        if(d[x] > d[y]) swap(x, y) ;
        d[x] += d[y] ;
        d[y] = x ;
        return true ;
    }
    bool same(int x, int y) {
        return find(x) == find(y) ;
    }
};



int main () {
    int n, m ;
    cin >> n >> m ;
    int ans = 0 ;
    vector<P> edge  ;
    rep(i, m){
        int a, b ;
        cin >> a >> b ;
        a-- ;  b-- ;
        edge.push_back(P(a, b))  ;
    }
    rep(i, m){
        UnionFind uf(n) ;
        rep(j, m){
            if(j == i){
                continue ;
            }
            else {
                int x = edge[j].first ;
                int y = edge[j].second ;
                uf.unite(x, y) ;
            }
        }
        int st = edge[i].first ;
        int gt = edge[i].second ;
        if(!uf.same(st, gt)){
            ans++ ;
        }
    }
    cout << ans << endl ;
}