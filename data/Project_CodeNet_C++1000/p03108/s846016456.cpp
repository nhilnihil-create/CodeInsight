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
    UnionFind (int n = 0) : d (n, -1) {}
    int find(int x){
        if(d[x] < 0) return x ;
        return find(d[x]) ;
    }
    bool unite (int x, int y){
        x = find(x) ;
        y = find(y) ;
        if(x == y) return false ;
        if(d[x] > d[y]) swap(x, y) ;
        d[x] += d[y] ;
        d[y] = x ;
        return true ;
    }
    bool same (int x, int y) {
        return find(x) == find(y) ;
    }
    int size (int x){
        return -d[find(x)] ;
    }
};



int main () {
    ll n, m ;
    cin >> n >> m ;
    UnionFind uf (n) ;
    vector<ll> ans ;
    vector<P> bd ;
    rep(i, m){
        int a, b ;
        cin >> a >> b ;
        a-- ; b-- ;
        bd.emplace_back(a, b) ;
    }
    ll dc = 0 ;
    for(int i = m - 1; i > 0; i--){
        int a = bd[i].first ;
        int b = bd[i].second ;
        if(uf.same(a, b)){
            ans.push_back(dc) ;
        }
        else {
            ll l = uf.size(a) ;
            ll p = uf.size(b) ;
            uf.unite(a,b) ;
            dc += l * p ;
            ans.push_back(dc) ;
        }
    }
    rep(i, m){
        if(i == m - 1){
            cout << n*(n-1)/2 << endl ;
        }
        else {
            cout << n*(n-1)/2 - ans[m - i - 2] << endl; 
        }
    }
}