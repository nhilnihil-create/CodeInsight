#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

struct UnionFind{
    vector<int> d;
    int n;
    UnionFind(int n):d(n,-1){}
    int root(int x){
        if(d[x]<0)return x;
        return d[x] = root(d[x]);
    }
    bool unite(int x,int  y){
        x = root(x);y = root(y);
        if(x==y) return false;
        if(d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x,int y) {return root(x) == root(y);}
    int size(int x) {return -d[root(x)];}
};

int main(){
    int n,m;cin >> n >> m;
    UnionFind u(n);
    rep(i,m){
        int x,y,z;cin >> x >> y >> z;
        --x;--y;
        u.unite(x,y);
    }

    int cnt = 0;
    rep(i,n) if(u.d[i]<0) cnt++;
    cout << cnt << endl;

    
    
}