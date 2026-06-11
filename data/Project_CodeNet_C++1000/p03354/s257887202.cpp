#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
struct UnionFind{
    vector<int> d;
    UnionFind(int n): d(n,-1){}
    int root(int x){
        if(d[x] <0)return x;
        return d[x] = root(d[x]);
    }
    int unite(int x,int y){
        x = root(x),y = root(y);
        if(x == y) return false;
        if(d[x] < d[y])swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    int size(int n){
        return -d[root(n)];
    }

};
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i,n)cin >> p[i];
    UnionFind uf(n);
    rep(i,m){
        //xとyを結ぶ
        int x,y;
        cin >> x >> y;
        x--;y--;
        uf.unite(x,y);

    }
    int ans = 0;
    rep(i,n){
        
        if(uf.root(i) == uf.root(p[i]-1))ans++;
    }
    cout << ans << endl;
    return 0;
}