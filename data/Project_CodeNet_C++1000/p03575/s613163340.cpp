#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;

struct UnionFind{
    vector<int> d;
    UnionFind(int n):d(n,-1){}
    int find(int x){
        if(d[x]<0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x,int  y){
        x = find(x);y = find(y);
        if(x==y) return false;
        if(d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x,int y) {return find(x) == find(y);}
    int size(int x) {return -d[find(x)];}
};

int main(){
    int n,m;cin >> n >> m;
    bool G[55][55];
    rep(i,55)rep(j,55) G[i][j] = false;
    vector<P> edge(m);
    rep(i,m) {
        int a,b;cin >> a >> b;
        --a;--b;
        edge[i] = make_pair(a,b);
        G[a][b] = true;
        G[b][a] = true;
    }
    queue<int> q;
    int ans = 0;
    rep(i,m){
        UnionFind tree(55);
        P p = edge[i];
        G[p.first][p.second] = false;
        G[p.second][p.first] = false;
        q.push(0);
        while(!q.empty()){
            int v = q.front();q.pop();
            //cout << v << endl;
            for(int nv = 0;nv<n;nv++){
                if(!G[v][nv]) continue;
                if(!tree.unite(v,nv)) continue;
                tree.unite(v,nv);
                q.push(nv);
            }
        }
        if(tree.size(0) != n) ans++;
        G[p.first][p.second] = true;
        G[p.second][p.first] = true;
    }
    cout << ans << endl;


}