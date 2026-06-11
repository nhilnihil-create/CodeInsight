#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = int64_t;

struct DisjointSet
{
    int g;
    vector<int> rank, p;
    DisjointSet(){}
    DisjointSet(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        rep(i, size) make_set(i);
    }
    void make_set(int x){
        p[x] = x;
        rank[x] = 0;
    }
    bool same(int x, int y){
        return find_set(x) == find_set(y);
    }
    int find_set(int x){
        if(x != p[x]) p[x] = find_set(p[x]);
        return p[x];
    }
    void unite(int x, int y){
        link(find_set(x), find_set(y));
    }
    void link(int x, int y){
        if(rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};

int main(){
    int n, m; cin >> n >> m;
    DisjointSet ds(n+1);
    rep(i, m) {
        int x, y, z; cin >> x >> y >> z;
        ds.unite(x, y);
    }

    int ans = 0;
    loop(i, 1, n+1) if(i == ds.p[i]) ans++;
    cout << ans << endl;

    return 0;
}